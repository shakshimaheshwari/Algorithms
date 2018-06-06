#include <iostream>

using namespace std;
void getInvCount(int *a, int n)
{
    int invcount=0;

    for(int i=1;i<n;i++)
    {
        int small =0;
        for(int j=i+1;j<n;j++)
            if(a[i] > a[j])
                small++;

        int great=0;
        for(int k=i-1;k>=0;k--)
            if(a[k]>a[i])
                great++;


        invcount+=great*small;

    }

    cout<<"The inversion count is::"<<invcount;
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

    getInvCount(a,n);
    return 0;
}
