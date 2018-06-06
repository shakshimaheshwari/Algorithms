#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findCrossOverIndex(vector<int>&nums, int start, int end, int target){
    if(target < nums[start]) return start;
    if(target > nums[end]) return end;

    int mid = start + (end- start)/2;

    if(nums[mid] <=target && nums[mid+1] > target) return mid;

    if(nums[mid] < target)
        return findCrossOverIndex(nums, mid+1, end, target);
    else
        return findCrossOverIndex(nums, start, mid-1, target);

}
vector<int> findClosestPair(vector<int>&nums,int target){
    vector<int>result;
    int l = findCrossOverIndex(nums,0,nums.size()-1, target);
    int r = l+1;
    if(nums[l] == target) l--;
    int count =0;
    while(l>=0 && r<nums.size()-1 && count <2){
        if(target - nums[l] < nums[r] - target){
            result.push_back(nums[l--]);
        }else{
            result.push_back(nums[r++]);
        }
        count++;
    }

    while(count < 2 && l>=0){
        result.push_back(nums[l--]);
        count++;
    }
    while(count <2 && r<nums.size()){
        result.push_back(nums[r++]);
        count++;
    }
    return result;
}
int main(){
    vector<int>result;
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>nums(n);
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    result = findClosestPair(nums, target);
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
}
