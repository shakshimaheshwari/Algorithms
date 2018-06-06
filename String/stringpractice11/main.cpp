#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;
void print(string s1, int i, int j)
{
    for(int i=0;i<j;i++)
    {
        cout<<s1[i];
    }
}
void findsmallestwindow(string s1, string s2)
{
    map<char, int>myMap;
    for(int i=0;i<s2.length();i++)
    {
        if(myMap.find(s2[i]) != myMap.end())
        {
            myMap[s2[i]]++;
        }
        else{
            myMap[s2[i]] =1;
        }
    }

    int i=0;
    int countofocc =0;
    int j = s1.length();
    int ans =INT_MAX;
    for(i=0;i<s1.length();i++)
    {
        while(i<j)
        {
            for(int k =i;k<j;k++)
            {
                if(myMap.find(s1[k])!= myMap.end())
                {
                    countofocc++;
                    myMap[s1[k]]--;
                }
            }
                if(countofocc == s2.length())
                {
                    ans = min(ans, j-i);
                    print(s1,i,j-1);
                }
                j--;
                countofocc =0;
            for(int f=0;f<s2.length();f++)
            {
                if(myMap.find(s2[f]) != myMap.end())
                {
                    myMap[s2[f]]++;
                }
                else
                {
                    myMap[s2[f]] = 1;
                }
            }

        }
        j = s1.length();


    }
    cout<<"The minimum window is::"<<ans;
}
int main()
{
    string s1,s2;
    cout<<"Enter the first string::";
    getline(cin, s1);
    cout<<"Enter the second string::";
    getline(cin, s2);

    findsmallestwindow(s1,s2);
    return 0;
}
