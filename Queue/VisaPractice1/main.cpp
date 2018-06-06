#include <iostream>
#include <vector>

using namespace std;
void segregateNumbers(vector<int>&nums){
    if(nums.size() == 0) return;
    int left = 0;
    int right = left+1;

    while(right < nums.size()){
        if(nums[left] && !nums[right]){
            swap(nums[left], nums[right]);
            left++;
        }else if(!nums[left]){
            left++;
        }
        right++;
    }
    return;
}
int main()
{
    vector<int>nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    segregateNumbers(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<"  ";
    }
    return 0;
}
