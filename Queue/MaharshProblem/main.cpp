#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
void calculateConsecutiveCharacterCount(string longest, unordered_map<char,int>&myMap){
    if(longest == "")return;
    int cur_count =1;
    int len = longest.size();
    for(int i=0;i< len;i++){
        if(i < len-1 && longest[i] == longest[i+1]){
            cur_count++;
        }else{
            if(myMap.find(longest[i])!= myMap.end()){
                if(cur_count > myMap[longest[i]]){
                    myMap[longest[i]] = cur_count;
                }
            }else{
                myMap[longest[i]] = cur_count;
            }
            cur_count =1;
        }

    }

    for(auto &i : myMap){
        cout<<i.first<<":"<<i.second;
    }
}

int main()
{
    string longest;
    cout<<"Enter the string::";
    cin>>longest;
    unordered_map<char, int>myMap;
    calculateConsecutiveCharacterCount(longest, myMap);
    return 0;
}
