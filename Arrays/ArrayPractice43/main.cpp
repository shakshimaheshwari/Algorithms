#include <iostream>
#include <string.h>
using namespace std;
void countSubstring(string s)
{
    int length = s.length();
    int countof1s =0;
    for(int i=0;i<length;i++)
    {
        if(s[i] == '1')
            countof1s++;

    }

    int result = (countof1s*(countof1s-1))/2;

    cout<<"The number of substrings that start with one and ends with one are::"<<result;
}
int main()
{
    string s;
    cout<<"Enter the binary string::";
    cin>>s;

    countSubstring(s);
    return 0;
}
