#include <iostream>

using namespace std;
void countEvenSum(int *a, int n)
{
    int temp[2]= {1,0};
    int result =0;
    int sum  =0;

    for(int i=0;i<=n-1;i++)
    {
        sum = ((sum + a[i])%2);
        temp[sum]++;

    }

    result = result + (temp[0] *(temp[0]-1)/2);
    result = result + (temp[1] * (temp[1]-1)/2);

    cout<<"The number of subarrays with even sum is::"<<result;
}
int main()
{
    int n;
    cout<<"Enter the elements::";
    cin>>n;

    int *a = new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];


    countEvenSum(a,n);
    return 0;
}
