#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int minDist(vector<int>&nums, int x, int y){
    if(nums.size() == 0) return 0;
    int min_dist = INT_MAX;
    int prev = -1;
    int n = nums.size();
    int i=0;
    for(;i<n;i++){
        if(nums[i] == x || nums[i] == y){
            prev= i;
            break;
        }
    }

    for(;i<n;i++){
        if(nums[i] == x || nums[i] == y){
            if(nums[i] != nums[prev] && (i - prev)<min_dist){
                min_dist = i-prev;
                prev = i;
            }else
                prev = i;
        }
    }
    return min_dist;
}
int main()
{
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(3);
    int x = 2;
    int y = 3;
    int res = minDist(nums,x,y);
    cout<<res<<endl;
    return 0;
}
