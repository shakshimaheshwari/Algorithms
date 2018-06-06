#include <iostream>
#include <vector>
#include <climits>

using namespace std;
pair<int,int> SubarrayLeastAverage(vector<int>&arr, int k){
    pair<int,int> res;
    if(arr.size() == 0) return res;
    int start = 0;
    int curr_sum =0;
    for(int i=0;i<k;i++){
        curr_sum += arr[i];
    }
    int min_sum = curr_sum;
    for(int i=k;i<arr.size();i++){
        curr_sum+= arr[i] - arr[i-k];
        if(curr_sum < min_sum){
            curr_sum  = min_sum;
            start = i-k+1;
        }
    }
    res = {start, start+k-1};
    return res;
}
int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(90);
    arr.push_back(20);
    arr.push_back(10);
    arr.push_back(50);
    arr.push_back(40);

    int k = 3;

    pair<int,int>res = SubarrayLeastAverage(arr,k);
    for(int i= res.first; i<=res.second;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
