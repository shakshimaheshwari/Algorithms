#include <iostream>

using namespace std;
void maxavgsubarray(int *a, int n , int k)
{
    int sum=0;

    for(int i=0;i<k;i++)
        sum+=a[i];

    int max_sum =sum;
    int max_end =k-1;

    for(int i=k;i<n;i++)
    {
        sum = sum+a[i] - a[i-k];
        if(sum > max_sum)
        {
            max_sum =sum;
            max_end = i;
        }

    }

    cout<<"The maximum subarray starts at index::"<<max_end-k+1;
}
int main()
{
    int n,k;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the length of the subarray::";
    cin>>k;
    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    maxavgsubarray(a,n,k);
    return 0;
}
