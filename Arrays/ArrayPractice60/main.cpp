#include <iostream>

using namespace std;
void inplacesort(int *a, int *b, int n,int m)
{
    for(int i=m-1;i>=0;i--)
    {
        int j;
        int last = a[n-1];
        for(j = n-1; j>=0 && a[j]>b[i];j--)
        {
            a[j+1] = a[j];
        }
        if(j!=n-1)
        {
            a[j+1] = b[i];
            b[i] = last;
        }


    }

    cout<<"Both arrays after modification is::";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"  ";
    cout<<endl;

    for(int i=0;i<m;i++)
        cout<<b[i]<<"  ";
    cout<<endl;
}
int main()
{
    int n, m;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the number of elements in array b::";
    cin>>m;
    int *a = new int[n];
    int *b = new int[m];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter the elements in array b::";
    for(int i=0;i<m;i++)
        cin>>b[i];

    inplacesort(a,b,n,m);
    return 0;
}
