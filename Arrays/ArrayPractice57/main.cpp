#include <iostream>

using namespace std;
void findMinAvgSubarray(int *a, int n, int k)
{
    if(n<k)
        return;

    int res_index =0;

    int cur_sum =0;

    for(int i=0;i<k;i++)
        cur_sum+= a[i];

    int min_sum = cur_sum;

    for(int i=k; i<n;i++)
    {
        cur_sum += a[i]-a[i-k];
        if(cur_sum < min_sum)
        {
            min_sum = cur_sum;
            res_index = (i-k+1);
        }


    }

    cout<<"The subarray with the minimum average lies in between "<< res_index << "and  "<< res_index+k-1;
}
int main()
{
    int n,k;
    cout<<"Enter the elements::";
    cin>>n;
    cout<<"Enter the subarray length::";
    cin>>k;
    int *a =new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    findMinAvgSubarray(a,n,k);
    return 0;
}
