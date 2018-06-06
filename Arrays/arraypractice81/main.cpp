#include <iostream>

using namespace std;
void reversearray(int *a, int n , int k)
{
    for(int i=0;i<n;i+=k)
    {
        int left = i;
        int right = min(i+k-1, n-1);
        while(left < right)
        {
            swap(a[left++], a[right--]);
        }
    }

    cout<<"The array after conversion is::";
    for(int i=0;i<n;i++)
        cout<<a[i];
}
int main()
{
    int n, k;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the elements:::";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the value of k::";
    cin>>k;
    reversearray(a,n,k);
    return 0;
}
