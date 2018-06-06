#include <iostream>

using namespace std;
void longestincreasingsubsequence(int *a, int n)
{
    int *lis = new int[n];
    int maximumlength =0;
    for(int i=0;i<n;i++)
        lis[i] =1;


    for(int i=1;i<n;i++)
        for(int j = 0;j<i;j++)
        if(a[i] > a[j] && lis[i] < lis[j] +1)
        lis[i] = lis[j] +1;

    for(int i=0;i<n;i++)
        if(maximumlength < lis[i])
        maximumlength = lis[i];

    cout<<"The maximum length of the list is::"<<maximumlength;

}
int main()
{
    int n;

    cout<<"Enter the value of n::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the values::";

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    longestincreasingsubsequence(a,n);
    return 0;
}
