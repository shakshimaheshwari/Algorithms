#include <iostream>
#include <climits>
using namespace std;
int maximumproductsubarray(int *a, int n)
{
    int max_fwd =INT_MIN;
    int max_bck = INT_MIN;
    int product =1;
    for(int i=0;i<n;i++)
    {
        product*=a[i];
        if(max_fwd < product)
        {
           max_fwd = product;
        }
    }

    product =1;
    for(int i=n-1;i>=0;i--)
    {
        product*=a[i];
        if(max_bck < product)
        {
            max_bck = product;
        }
    }

    int final_prod = max(max_fwd, max_bck);
    return final_prod;
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    int x = maximumproductsubarray(a,n);
    cout<<"The maximum product is::"<<x;
    return 0;
}
