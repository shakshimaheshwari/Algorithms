#include <iostream>
#include <string>
#include <map>
using namespace std;
void firstnonrepeating(string s1, int n)
{
    map<char, int>myMap;
    for(int i=0;i<s1.length();i++)
    {
        if(myMap.find(s1[i]) != myMap.end())
        {
            myMap[s1[i]]++;
        }
        else
        {
            myMap[s1[i]] = 1;
        }
    }
    int index;
   for(int i=0;i<s1.length();i++)
   {
       if(myMap[s1[i]] == 1)
       {
           index = i;
           break;
       }
   }

   cout<<"The first non repeating character is::"<<s1[index];
}
int main()
{
    string s1;
    cout<<"Enter the string::";
    getline(cin, s1);
    firstnonrepeating(s1, s1.length());
    return 0;
}
