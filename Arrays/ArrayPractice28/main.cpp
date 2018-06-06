#include <iostream>

using namespace std;
void numberoftriangles(int *a, int n)
{
    int i,j,k;
    int countoftriangles =0;
    for(i=0;i<n;i++)
    {
        k = i+2;
        for(j= i+1;j<n;j++)
        {
            while(k<n && a[i]+a[j] > a[k])
                k++;

            countoftriangles += k-j-1;
        }
    }

    cout<<"The number of triangles is::"<<countoftriangles;
}
int main()
{
    int n;
    cout<<"Enter number of elements::";
    cin>>n;

    int *a = new int[n];

    cout<<"Enter the values::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    numberoftriangles(a,n);
    return 0;
}
