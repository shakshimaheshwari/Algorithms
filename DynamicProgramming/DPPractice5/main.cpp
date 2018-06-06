#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int longestBitonicSubsequence(vector<int>&input){
    int n = input.size();
    vector<int>lis(n);
    vector<int>lds(n);

    lis[0] = 1;
    for(int i=1;i<n;i++){
        lis[i] = INT_MIN;
        for(int j=0;j<i;j++){
            if(input[i] > input[j] && lis[i] < lis[j]+1){
                lis[i] = lis[j]+1;
            }
        }
    }

    lds[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        lds[i] = INT_MIN;
        for(int j = n-1;j>i;j--){
            if(input[i] > input[j] && lds[i] < lds[j]+1){
                lds[i] = lds[j]+1;
            }
        }
    }

    int maximum =0;
    for(int i=0;i<n;i++){
        if(maximum < lis[i] + lds[i]-1){
            maximum = lis[i] + lds[i] -1;
        }
    }
    return maximum;
}
int main()
{
    int n;
    cout<<"Enter the value of n::";
    cin>>n;
    cout<<"Enter the elements::";
    vector<int>input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    int length = longestBitonicSubsequence(input);
    cout<<length;
    return 0;
}
