#include <iostream>

using namespace std;
void maxlengthbitonicsubarray(int *a, int n)
{
    int *inc = new int[n];
    int *dec = new int[n];
    int maxvalue;

    inc[0] = 1;
    dec[n-1] = 1;

    for(int i=1;i<n;i++)
        inc[i] = (a[i] > a[i-1])? inc[i-1] +1 : 1;

    for(int j = n-2;j>=0;j--)
        dec[j] = (a[j]>a[j+1])?dec[j+1]+1:1;

    maxvalue = inc[0] + dec[0]-1;

    for(int i=0;i<n;i++)
        if(inc[i]+dec[i]-1 > maxvalue)
        maxvalue = inc[i]+dec[i]-1;

    cout<<"The maximum length of the bitonic subarray is::"<<maxvalue;
}
int main()
{
    int n;

    cout<<"Enter the value of n::";
    cin>>n;
    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    maxlengthbitonicsubarray(a,n);
    return 0;
}
