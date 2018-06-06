#include <iostream>
#include <string>
#include <map>
using namespace std;
void dupremoval(string s)
{
    map<char,int>myMap;

    for(int i=0;i<s.length();i++)
    {
        if(myMap.find(s[i]) != myMap.end())
        {
            myMap[s[i]]++;
        }
        else{
            myMap[s[i]] =1;
        }
    }

    for(map<char,int>::iterator iter = myMap.begin();iter != myMap.end();iter++)
    {
        cout<<iter->first;
    }
}
void inplacedupremoval(string s)
{
    int binhash[256] = {0};
    int in_ind = 0;
    int res_index=0;
    while(in_ind < s.length())
    {
        char temp = s[in_ind];
        if(binhash[temp] == 0)
        {
            binhash[temp] = 1;
            s[res_index] = s[in_ind];
            res_index++;
        }
        in_ind++;
    }
    s[res_index] = '\0';
    cout<<"The string after removal of duplicates is::"<<s;
}
int main()
{
    string s;
    cout<<"Enter the string which you want to remove duplicates from::";
    getline(cin,s);

    //dupremoval(s);
    inplacedupremoval(s);
    return 0;
}
