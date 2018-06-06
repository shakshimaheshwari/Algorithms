#include <iostream>

using namespace std;
void largestsubarray(int *a, int n)
{
    int max_length =0;
    for(int i=0;i<n-1; i++)
    {
        int mx = a[i];
        int mn = a[i];

        for(int j=i+1;j<n;j++)
        {
            mx = max(mx,a[j]);
            mn = min(mn,a[j]);

            if(mx- mn == j-i)
                max_length = max(max_length, mx-mn+1);
        }
    }
    cout<<"The maximum length of the subarray is::"<<max_length;
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the array elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    largestsubarray(a, n);
    return 0;
}
