#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
string removeMatchingPairs(string s){
    if(s.length() == 0) return s;
    string result="";
    stack<char>stk;
    for(int i=0;i<s.length();i++){
        if(!stk.empty() && (tolower(stk.top()) == tolower(s[i]))){
            stk.pop();
        }else
            stk.push(s[i]);
    }
    while(!stk.empty()){
        result+=stk.top();
        stk.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    string s="abcdDCB";
    string result =removeMatchingPairs(s);
    cout<<result;
    return 0;
}
