#include <iostream>

using namespace std;
void rearrangeelements(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        a[i] += (a[a[i]]%n)*n;

    }
    for(int i=0;i<n;i++)
    {
        a[i] = a[i]/n;
    }

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


    rearrangeelements(a,n);
    return 0;
}
