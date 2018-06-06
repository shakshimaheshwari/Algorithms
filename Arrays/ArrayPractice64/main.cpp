#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
void mindiff(int *a, int n)
{
    sort(a, a+n);
    int min_diff =INT_MAX;
    int cur_diff =0;
    for(int i=0;i<n-1;i++)
    {
        cur_diff = a[i+1]-a[i];
        if(cur_diff < min_diff)
            min_diff = cur_diff;
    }

    cout<<"The minimum difference is::"<<min_diff;
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

    mindiff(a,n);
    return 0;
}
