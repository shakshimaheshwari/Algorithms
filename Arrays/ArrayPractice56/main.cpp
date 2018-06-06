#include <iostream>
#include <algorithm>

using namespace std;
void counttriplets(int *a, int n, int sum)
{
    int countoftriplets=0;
    sort(a, a+n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1,k=n-1;j<k;)
        {
            if(a[i]+a[j]+a[k]<sum)
            {
                countoftriplets+=k-j;
                j++;
            }
            else if(a[i]+a[j]+a[k] >= sum)
                k--;
        }
    }

    cout<<"The number of triplets is::"<<countoftriplets;
}
int main()
{
    int n, sum;
    cout<<"Enter the elements::";
    cin>>n;

    cout<<"Enter the sum::";
    cin>>sum;
    int *a = new int[n];
    cout<<"enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    counttriplets(a,n, sum);
    return 0;
}
