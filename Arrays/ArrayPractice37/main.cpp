#include <iostream>
#include <climits>

using namespace std;
void smallestsubarray(int *a, int n, int x)
{
    int startindex=0;
    int endindex =0;
    int min_length = INT_MAX;
    int cur_sum=0;
    while(endindex<n)
    {
        while(cur_sum <= x && endindex<n)
            cur_sum+=a[endindex++];

        while(cur_sum>x && startindex<n)
        {
            if(endindex - startindex < min_length)
                min_length = endindex-startindex;

            cur_sum -= a[startindex++];
        }
    }


    cout<<"The minimum length of the subarray is::"<<min_length;
}
int main()
{
    int n, x;
    cout<<"Enter the number of elements::";
    cin>>n;


    cout<<"Enter the summation::";
    cin>>x;
    int *a = new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    smallestsubarray(a,n,x);
}
