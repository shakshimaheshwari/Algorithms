#include <iostream>
#include<algorithm>

using namespace std;
void sumoftriplets(int *a, int n, int sum)
{
    sort(a,a+n);
    for(int k=0;k<n;k++)
    {
        for(int i=k+1,j=n-1;i<j;)
        {
            if(a[i]+a[j]+a[k] == sum)
            {
                cout<<"Sum found at indexes::"<<a[i]<<","<<a[j]<<","<<a[k];
                break;
            }
            else if(a[k]+a[i]+a[j]< sum)
                i++;
            else
                j--;
        }
    }
}
int main()
{
    int n, sum;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the sum::";
    cin>>sum;
    int *a = new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];


    sumoftriplets(a,n, sum);
    return 0;
}
