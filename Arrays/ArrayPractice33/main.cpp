#include <iostream>

using namespace std;
void rearrange(int *a, int n)
{
    int i=-1;
    for(int j=0;j<n;j++)
    {
        if(a[j] <0)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    int pos = i+1;
    int neg =0;


    while(pos<n && neg < pos && a[neg]<0)
    {
        swap(a[pos], a[neg]);
        neg+=2;
        pos++;

    }

    cout<<"The array after modification is::";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
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

    rearrange(a,n);
    return 0;
}
