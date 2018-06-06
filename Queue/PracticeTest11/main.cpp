#include <iostream>
#include <vector>

using namespace std;
int calcDPSteps(int n){
    if(n == 0) return 0;
    vector<int>dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] += dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}
int main()
{
    int n;
    cout<<"Enter the value of the steps::";
    cin>>n;
    int result = calcDPSteps(n);
    cout<<result;
    return 0;
}
