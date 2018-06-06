#include <iostream>

using namespace std;
void reversealternate(int *a, int n, int k)
{
    for(int i=0;i<n;i+=2*k)
    {
        int left = i;
        int right = min(n-1, i+k-1);

        while(left <right)
        {
            swap(a[left++], a[right--]);
        }
    }

    cout<<"The array formed by reversing alternative group is::";
    for(int i=0;i<n;i++)
        cout<<a[i] << "   ";
}
int main()
{
    int n,k;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the value of k::";
    cin>>k;

    reversealternate(a,n,k);
    return 0;
}
