#include <iostream>

using namespace std;
void strictlyincreasingsubarray(int *a, int n)
{
    int cnt =0;
    int len =1;

    for(int i=0;i<n-1;i++)
    {
        if(a[i] < a[i+1])
            len++;

        else{
            cnt+= ((len * (len-1))/2);
            len =1;
        }
    }
    if(len>1)
      cnt+= ((len * (len-1))/2);

    cout<<"The number of strictly increasing subarrays is::"<<cnt;
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

    strictlyincreasingsubarray(a,n);
    return 0;
}
