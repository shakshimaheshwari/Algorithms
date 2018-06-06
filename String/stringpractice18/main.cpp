#include <iostream>
#include <string>

using namespace std;

bool checkPattern(string s1, string pattern)
{
    int len = pattern.length();
    if(len > s1.length())
        return false;
    for(int i=0;i<len-1;i++)
    {
        char x = pattern[i];
        char y = pattern[i+1];

        int last = s1.find_last_of(x);
        int first = s1.find_first_of(y);

        if(last == string::npos || first == string::npos || last>first)
        return false;
    }
    return true;
}
int main()
{
    string s1, pattern;
    cout<<"Enter the string::";
    getline(cin,s1);

    cout<<"Enter the pattern::";
    getline(cin, pattern);

    if(!checkPattern(s1, pattern))
    {
        cout<<"The string does not follow the pattern";
    }
    else
    {
        cout<<"The string follows the pattern";
    }
    return 0;
}
