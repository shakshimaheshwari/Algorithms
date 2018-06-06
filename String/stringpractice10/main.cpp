#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;
void runlengthencoding(string s1)
{
    map<char, int>myMap;
    int length = s1.length();
    string result ="";
    for(int i=0;i<length;i++)
    {
        if(myMap.find(s1[i]) != myMap.end())
        {
            myMap[s1[i]]++;
        }
        else{
            myMap[s1[i]] = 1;
        }
    }

    for(int i=0;i<length;)
    {
       int countofocc = myMap[s1[i]];
       stringstream out;
       out<<countofocc;
       result += s1[i] + out.str() ;
       i += countofocc-1;
    }

    cout<<"The final run length encoding is::"<<result;
}
int main()
{
    string s1;
    cout<<"Enter the string::";
    getline(cin, s1);

    runlengthencoding(s1);
    return 0;
}
