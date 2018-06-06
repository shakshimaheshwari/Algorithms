#include <iostream>

using namespace std;
void missingelement(int *a, int *b, int n , int m)
{
    if(n!=m-1 && m != n-1)
    {
        cout<<"Invalid Input";
        return;
    }
    int res =0;
    for(int i=0;i<n;i++)
        res = res ^a[i];

    for(int i=0;i<m;i++)
        res = res^ b[i];

    cout<<"The missing element is ::"<<res<<endl;

}
int main()
{
    int n, m;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the number of elements::";
    cin>>m;

    int *a = new int[n];
    int *b = new int[m];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<"Enter the elements in array b::";
    for(int i=0;i<m;i++)
        cin>>b[i];

    missingelement(a,b,n,m);

    return 0;
}
