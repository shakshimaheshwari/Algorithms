#include <iostream>

using namespace std;
void maxwater(int *a, int n)
{
    int left[n];
    int right[n];
    int water=0;
    left[0] = a[0];
    for(int i=1;i<n;i++)
        left[i] = max(left[i-1],a[i]);

    right[n-1] = a[n-1];

    for(int i=n-2;i>=0;i--)
        right[i] = max(right[i+1],a[i]);

    for(int i=0;i<n;i++)
        water += min(left[i], right[i])-a[i];


    cout<<"The maximum water collected is::"<<water;

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

    maxwater(a,n);
    return 0;
}
