#include <iostream>
#include<string>
#include<vector>
#include <climits>
#include <math.h>
#include <algorithm>
#include <sstream>
using namespace std;
void maxReachProbability(vector<int>&nums){
    int opt[nums.size()];
    opt[0] = 0;
    vector<int>steps(nums.size(),0);
    for(int i=1;i<nums.size();i++){

        opt[i] = INT_MAX;
        for(int j = 0;j<i;j++){
            if(i<=nums[j]+j && nums[j]!= INT_MAX){
                if(opt[i] > opt[j]+1){
                    opt[i] = opt[j]+1;
                    steps[i] = j;
                }
            }
        }
    }
    int j = opt[nums.size()-1];
    int rs[j];
    int len = j-1;
    while(j != 0)
    {
        rs[len--] = steps[j];
        j = steps[j];
    }
    for (int i = 0 ; i < steps.size() ; i++ )
    cout << rs[i] <<endl;
}
int main()
{
    int num;
    vector<int>input;

    input.push_back(1);
    input.push_back(3);
    input.push_back(6);
    input.push_back(1);
    input.push_back(0);
    input.push_back(9);

    maxReachProbability(input);

}
