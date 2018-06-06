#include <iostream>

using namespace std;
int MaxArraySum(int *a, int n)
{
    int max_so_far = a[0];
    int curr_max = a[0];
    for(int i=0;i<n;i++)
    {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(curr_max, max_so_far);
    }

    return max_so_far;
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

    int max_sum = MaxArraySum(a, n);
    cout<<"The maximum contiguos sum is::"<<max_sum;
    return 0;
}
