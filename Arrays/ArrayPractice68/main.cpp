#include <iostream>

using namespace std;
void minoperations(int *a, int n)
{
    int ans =0;
    for(int i=0, j= n-1;i<=j;)
    {
        if(a[i] == a[j])
        {
            i++;
            j--;
        }
        else if( a[i] > a[j])
        {
            j--;
            a[j]+=a[j+1];
            ans++;
        }
        else
        {
            i++;
            a[i]+=a[i-1];
            ans++;
        }
    }

    cout<<"The minimum number of operations required::"<<ans;
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

    minoperations(a,n);
    return 0;
}
