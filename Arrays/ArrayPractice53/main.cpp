#include <iostream>

using namespace std;
void maxSum(int *a, int n)
{
    int arrSum =0;
    int currval =0;

    for(int i=0;i<n;i++)
    {
        arrSum = arrSum +a[i];
        currval = currval + (i*a[i]);
    }

    int maxval = currval;

    for(int j=1;j<n;j++)
    {
        currval = currval+ arrSum-n*a[n-j];
        if(currval > maxval)
            maxval = currval;

    }
    cout<<"The maximum value is::"<<maxval;
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a= new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    maxSum(a,n);
    return 0;
}
