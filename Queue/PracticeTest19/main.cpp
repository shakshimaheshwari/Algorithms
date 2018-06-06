#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <math.h>

using namespace std;
bool repeatedSubstringPattern(string s){
    if(s.length() == 0) return true;
    for(int i=1;i<s.length();i++){
        string word = s.substr(0,i);
        if(s.length()%word.length()!=0) continue;
        if(word.length() == s.length()) return false;
        string result=  "";
        while(result.length() < s.length()){
            result += word;
        }
        if(result == s) return true;
    }
    return false;
}
int main()
{
    string s = "abcabcabcaba";
    bool ret = repeatedSubstringPattern(s);
    cout<<ret;
    return 0;
}
