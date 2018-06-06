#include <iostream>

using namespace std;
void max1sindex(int *a, int n)
{

    int prev_zero =-1;
    int prev_prev_zero =-1;
    int max_count =0;
    int max_index =0;

    for(int i=0;i<n;i++)
    {
        if(a[i] == 0)
        {
            if(i-prev_prev_zero > max_count)
            {
                max_count = i-prev_prev_zero;
                max_index = i;
            }

            prev_prev_zero = prev_zero;
            prev_zero =i;
        }
    }

    if(n-prev_prev_zero > max_count)
        max_index = prev_zero;

    cout<<"The maximum count is::"<<max_count;
}
int main()
{
    it n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];


    max1sindex(a,n);
    return 0;
}
