#include<iostream>
#include<vector>
#include<string>
#include <climits>

using namespace std;
int minimumnumberofjumps(vector<int>&input)
{
    int *dp = new int[input.size()];
    dp[0] = 0;
    for(int i=1; i<input.size();i++)
    {
        dp[i] = INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(dp[j]!=INT_MAX && i<=j+input[j])
            {
                dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }
    return dp[input.size()-1];
}
int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int>input;
    for(int i=0;i<n;i++)
        input.push_back(a[i]);
    int output = minimumnumberofjumps(input);
    cout<<output;
    return 0;
}
