#include <iostream>
#include <string>
#include <map>

using namespace std;
void charcount(string s)
{
    map<char,int> m;

    for(int i=0;i<s.length();i++)
    {
        if(m.find(s[i])!= m.end())
        {
            m[s[i]]++;
        }
        else{
            m[s[i]] = 1;
        }
    }
    int maximum =0;
    char maxchar = m[s[0]];
    for(map<char, int>::  iterator iter = m.begin(); iter!= m.end();iter++)
    {
        if(iter->second > maximum)
        {
            maximum = iter->second;
            maxchar = iter->first;
        }
    }

    cout<<"The maximum occurring character is::"<<maxchar;
}
int main()
{
    string s;
    cout<<"Enter the string::";
    getline(cin,s);

    charcount(s);
    return 0;
}
