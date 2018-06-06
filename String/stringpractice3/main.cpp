#include <iostream>
#include <string>
#include <map>
using namespace std;
void deleteoccurences(string s1, string s2)
{
    int firstlength = s1.length();
    int secondlength = s2.length();

    map<char, int>myMap;

    for(int i=0;i<s2.length();i++)
    {
        if(myMap.find(s2[i]) != myMap.end())
        {
            myMap[s2[i]]++;
        }
        else{
            myMap[s2[i]] = 1;
        }
    }

    for(int i=0;i<s1.length();i++)
    {
        if(myMap.find(s1[i]) != myMap.end())
        {
            continue;
        }
        else{
            cout<<s1[i];
        }
    }
}
int main()
{
    string s1, s2;
    cout<<"Enter the first string::";
    getline(cin, s1);
    cout<<"Enter the second string::";
    getline(cin,s2);

    deleteoccurences(s1,s2);
    return 0;
}
