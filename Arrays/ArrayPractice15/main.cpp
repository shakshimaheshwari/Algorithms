#include <iostream>

using namespace std;
void maxdiff(int *a, int n)
{
    int maxDiff;
    int *lMin = new int[n];
    int *rMax = new int[n];

    lMin[0] = a[0];
    for(int i=1;i<n;i++)
    lMin[i] = min(a[i], lMin[i-1]);


    rMax[n-1] = a[n-1];

    for(int j=n-2;j>=0;j--)
        rMax[j] = max(a[j], rMax[j+1]);

    int i=0;
    int j=0;
    maxDiff = -1;
    while(j<n && i<n)
    {
        if(lMin[i] < rMax[j])
        {
            maxDiff = max(maxDiff, j-i);
            j= j+1;
        }
        else
            i = i+1;
    }

    cout<<"The maximum difference is::"<<maxDiff;
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int*a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];


    maxdiff(a,n);
    return 0;
}
