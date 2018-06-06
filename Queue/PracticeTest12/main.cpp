#include <iostream>
#include<vector>

using namespace std;
int magicIndex(vector<int>nums, int start, int end){
    if(start > end) return -1;
    int mid = start + (end - start)/2;

    if(nums[mid] == mid) return mid;
    int leftIndex = min(mid-1, nums[mid]);
    int left = magicIndex(nums, start, leftIndex);
    if(left >=0){
        return left;
    }

    int rightIndex= max(mid+1, nums[mid]);
    return magicIndex(nums, rightIndex, end);
}
int main()
{
    vector<int>arr;
    arr.push_back(-10);
    arr.push_back(-5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(12);
    arr.push_back(13);
    int index = magicIndex(arr, 0, arr.size()-1);
    cout<<index<<endl;
    return 0;
}
