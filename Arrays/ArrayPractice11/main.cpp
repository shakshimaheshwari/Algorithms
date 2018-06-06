#include <iostream>
#include <stdlib.h>

using namespace std;
void duplicatesfinding(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[abs(a[i])]>=0)
        {
            a[abs(a[i])] = -a[abs(a[i])];
        }
        else {
            cout<<" "<<abs(a[i]);
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];

    cout<<"enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];


    duplicatesfinding(a,n);
    return 0;
}
