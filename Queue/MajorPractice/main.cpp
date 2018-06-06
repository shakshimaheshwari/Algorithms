#include <iostream>
#include <vector>
using namespace std;
void modifyVector(vector<int>&nums){
    int left =0;
    int right = left+1;
    while(right < nums.size()){
        if(!nums[left] && nums[right]){
            right++; left++;
        }else if(nums[left] && nums[right]){
            right++;
        }else if(nums[left] && !nums[right]){
            swap(nums[left], nums[right]);
            left++;
        }else if(!nums[left] && !nums[right]){
            left++; right++;
        }
    }
    return;
}
int main()
{
    vector<int>input;
    input.push_back(0);
    input.push_back(0);
    input.push_back(1);
    input.push_back(1);
    input.push_back(0);
    /*input.push_back(1);
    input.push_back(1);
    input.push_back(0);*/
    modifyVector(input);
    for(int i=0;i<input.size();i++){
        cout<<input[i];
    }
    return 0;
}
