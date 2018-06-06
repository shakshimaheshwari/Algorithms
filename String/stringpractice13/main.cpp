#include <iostream>

using namespace std;
static int i=0;
static int j=0;
void interleavedstringrecur(string s1, string s2, char *iStr, int n, int m, int index)
{
    if(m == 0 && n ==0)
    {
            cout<<iStr;
        cout<<endl;
    }
    if(n!=0)
    {
        iStr[index] = s1[0];
        interleavedstringrecur(s1.substr(i,n),s2, iStr,n-1, m , index+1);
    }
    if(m!=0)
    {
        iStr[index] = s2[0];
        interleavedstringrecur(s1, s2.substr(j,m), iStr, n, m-1, index+1);
    }
}
void interleavedstrings(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    char *iStr = new char[n+m+1];
    iStr[m+n] = '\0';

    interleavedstringrecur(s1, s2, iStr, n , m, 0);
}
int main()
{
    string s1,s2;
    cout<<"Enter the first string::";
    getline(cin, s1);
    cout<<"Enter the second string::";
    getline(cin, s2);

    interleavedstrings(s1,s2);
    return 0;
}
