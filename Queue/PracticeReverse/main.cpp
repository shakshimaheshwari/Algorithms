#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;
int edit1distance(string s1, string s2)
{

    if(s2.length() > s1.length()) return edit1distance(s2,s1);
    if(s1.length() == 1 && s2.length()==0)
        return 1;

    int count =0;
    int i,j;
    for(i=0, j=0;i<s1.length()&& j<s2.length();)
    {
        if(s1[i] == s2[j]){continue;}
        else{
            count++;
            j++;
        }
        i++;
    }
    i = s1.length();
    if(count == 1)
    {
        if(abs(i-j)==1){
            return 0;
        }
        else
        return 1;
    }
    else
        return 0;
    /*map<char,int>myMap;
    for(int i=0;i<s1.length();i++)
    {
        myMap[s1[i]]++;
    }
    if(abs(s1.length()-s2.length())>1)
        return 0;
    if(abs(s1.length()-s2.length()) == 1 || (s1.length() == s2.length()))
    {
        for(int i=0;i<s2.length();i++)
        {
            if(myMap.find(s2[i])!= myMap.end())
            {
                if(myMap[s2[i]]>0)
                {
                    myMap[s2[i]]--;
                }
                else
                    count++;
            }
            else
                count++;
        }
    }
    if(abs(s1.length()-s2.length()) == 1)
        count++;
    if(count == 1)
        return 1;
    else
        return 0;*/
}

int main()
{
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);

    int flag = edit1distance(s1,s2);

    if(flag == 1)
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
