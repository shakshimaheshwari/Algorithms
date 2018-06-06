#include <iostream>

using namespace std;
void maxProductSubarray(int *a, int n)
{
    int min_ending_here =1;
    int max_ending_here = 1;
    int max_so_far = 1;

    for(int i=0;i<n;i++)
    {
        if(a[i]> 0)
        {
            max_ending_here = max_ending_here*a[i];
            min_ending_here = min(min_ending_here*a[i],1);
        }
        else if(arr[i] == 0)
        {
            max_ending_here =1;
            min_ending_here =1;
        }
        else
        {
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here*a[i],1);
            min_ending_here = temp*a[i];
        }

        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the values::";

    for(int i=0;i<n;i++)
        cin>>a[i];


    maxProductSubarray(a,n);
    return 0;
}
