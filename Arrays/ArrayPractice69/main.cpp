#include <iostream>
#include <algorithm>

using namespace std;
int getMinDiff(int *a, int n, int k)
{
    sort(a, a+n);
    int maxe = a[n-1];
    int mine = a[0];

    if(k >= maxe-mine)
    {
        for(int i=0;i<n;i++)
            a[i]+=k;
        return (maxe-mine);
    }

    a[0] += k;
    a[n-1]-=k;

    int new_max = max(a[0], a[n-1]);
    int new_min = min(a[0],a[n-1]);

    for(int j=1; j< n-1; j++)
    {
        if(a[j] < new_min)
            a[j]+=k;

        else if(a[j]> new_max)
            a[j]-=k;

        else if((a[j] - new_min) > (new_max - a[j]))
            a[j]-=k;

        else
            a[j] += k;

        new_min = min(a[j] , new_min);
        new_max = max(a[j], new_max);
    }

    return (new_max - new_min);

}
int main()
{
    int n, k;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the value of k::";
    cin>>k;
    int *a = new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
    cin>>a[i];

    int value = getMinDiff(a,n,k);
    cout<<"Minimum of the maximum difference::"<<value;
    return 0;
}
