#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void allpermutlexico(string s1, char *data, int index, int last)
{
    int len = s1.length();
    for(int i=0;i<len;i++)
    {
        data[index]= s1[i];
        if(index == last)
            cout<<data<<endl;
        else
            allpermutlexico(s1,data,index+1,last);
    }
}

void permutationlexic(string s1)
{
    int length = s1.length();
    char *data = new char[length];
    sort(s1.begin(), s1.end());
    allpermutlexico(s1, data, 0, length-1);
}
int main()
{
    string s1;
    cout<<"Enter the string::";
    getline(cin,s1);

    permutationlexic(s1);
    return 0;
}
