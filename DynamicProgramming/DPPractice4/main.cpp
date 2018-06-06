#include <iostream>

using namespace std;
void longestincreasingsubseq(int *a, int n)
{
    int *lis = new int[n];

    for(int i=1;i<n;i++)
    {
        for(int j=0;)
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the array elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    longestincreasingsubseq(a,n);
    return 0;
}
