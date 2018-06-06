#include <iostream>

using namespace std;
void equilibriumindex(int *a, int n)
{
    int leftsum =0;
    int rightsum;
    int sum = 0;

    for(int i=0;i<n;i++)
        sum+=a[i];

    for(int i=0;i<n;i++)
    {
        rightsum = sum - a[i];
        sum = sum - a[i];
        if(leftsum == rightsum)
        {
            cout<<i;
            break;
        }
        leftsum +=a[i];
    }

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


    equilibriumindex(a,n);
    return 0;
}
