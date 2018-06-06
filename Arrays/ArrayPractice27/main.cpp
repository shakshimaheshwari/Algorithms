#include <iostream>

using namespace std;
int kadane(int *a, int n)
{
    int max_sum =0;
    int max_so_far =0;
    for(int i=0;i<n;i++)
    {
        max_sum = max_sum +a[i];

        if(max_sum <0)
            max_sum = 0;

        if(max_so_far < max_sum)
            max_so_far =max_sum;

    }
    return max_so_far;
}
void maxcirculararraysum(int *a, int n)
{
    int max_sumkadane = kadane(a,n);

    int max_wrap =0;

    for(int i=0;i<n;i++)
    {
        max_wrap = max_wrap+ a[i];

        a[i] = -a[i];
    }

    max_wrap = max_wrap + kadane(a,n);

    int result = (max_wrap > max_sumkadane)? max_wrap:max_sumkadane;
    cout<<result;
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];

    cout<<"Enter the values::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    maxcirculararraysum(a,n);
    return 0;
}
