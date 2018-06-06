#include <iostream>

using namespace std;
void rearrange(int *a, int n)
{
    int i=-1;
    int j=n;

    while(i<j)
    {
        while(a[++i]>0);
        while(a[--j]<0);

        if(i<j)
            swap(a[i], a[j]);
    }
    cout<<"Array after swap is::";
    for(int l=0;l<n;l++)
        cout<<a[l];
    if(i==0 || i==n)
        return;
    int k=0;

    while(i<n && k<n)
    {
        swap(a[i], a[k]);
        i = i+1;
        k = k+2;
    }

    cout<<"The modified array is::";
    for(int m=0;m<n;m++)
        cout<<a[m];
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
