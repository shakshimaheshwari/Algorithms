#include <iostream>
#include <stdlib.h>

using namespace std;
int segregate(int *a, int n)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    return j;
}
void smallestmissingnumber(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        if(abs(a[i])-1<n && a[abs(a[i])-1] >0)
           a[abs(a[i])-1] = -a[abs(a[i])-1];

    }

        for(int i=0;i<n;i++)
            if(a[i]>0)
            cout<<"The smallest positive number is::"<<i+1;

}
void smallestpositivenumber(int *a, int n)
{
    int j = segregate(a,n);
    smallestmissingnumber(a+j, n-j);

}
int main()
{
    int n;
    cout<<"Enter the value of n::";
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    smallestpositivenumber(a,n);
    return 0;
}
