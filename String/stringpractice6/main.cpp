#include <iostream>
#include <string>

using namespace std;
void permutation(string s1, int start, int endlength)
{
    int i;
    if(start == endlength)
        cout<<s1<<endl;

    else
    {
        for(i=start;i<=endlength;i++)
        {
            swap(s1[start], s1[i]);
            permutation(s1,start+1, endlength);
            swap(s1[start], s1[i]);
        }
    }
}
int main()
{
    string s1;
    cout<<"Enter the string::";
    getline(cin, s1);
    permutation(s1,0,s1.length()-1);
    return 0;
}
