#include <iostream>
#include <algorithm>
using namespace std;
void rearrange(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        int temp = a[i];

        while(temp > 0)
        {
            int j = (i<n/2)? (2*i+1):(2*(n-i-1));
            if(i==j)
            {
                a[i] = -temp;
                break;
            }
            swap(temp, a[j]);

            a[j] = -a[j];
            i=j;
        }
    }
    for(int i=0;i<n;i++)
        a[i] = -a[i];

    cout<<"The modified array is::";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"  ";
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

    rearrange(a,n);
    return 0;
}
