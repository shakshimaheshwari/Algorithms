#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std::tr1;
using namespace std;
string encodestring(string pattern)
{
    unordered_map<char, int>myMap;
    int j=0;
    string res="";
    for(int i=0;i<pattern.length();i++)
    {
        if(myMap.find(pattern[i]) == myMap.end())
            myMap[pattern[i]] = j++;

        res+= to_string(myMap[pattern[i]]);
    }

    return res;
}

void findmatchedstring(unordered_set<string>dict, string pattern)
{
    int length = pattern.length();
    string hashstring = encodestring(pattern);

    for(int i=0;i<dict.size();i++)
    {
        if(dict[i].length() == length && encodestring(dict[i]) == hashstring)
        {
            cout<<dict[i];
        }
    }
}
int main()
{
    unordered_set<string> dict = {"abb", "abc","xyz","xyy"};
    string pattern = "foo";
    findmatchedstring(dict, pattern);
    return 0;
}
