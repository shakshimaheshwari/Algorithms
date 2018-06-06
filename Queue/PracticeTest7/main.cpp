#include <iostream>

using namespace std;
int CommonSub(string s1, string s2){
    if(s1.length() == 0 && s2.length() == 0){
        return 0;
    }
    int j=0;
    vector<vector<int>>LCS(s1.length()+1, vector<int>)
}
int main()
{
    string s1 = "apple";
    string s2 = "app";

    int n = CommonSub(s1,s2);
    cout<<n;
    return 0;
}
