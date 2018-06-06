#include <iostream>

using namespace std;
void rearrange(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] += (arr[arr[i]]%n)*n;

    }

    for(int i=0;i<n ;i++)
    {
        arr[i] = arr[i]/n;
    }

    cout<<"The new array after modification is::";
    for(int i=0;i<n;i++)
        cout<<arr[i] <<"   ";
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
