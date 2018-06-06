#include <iostream>

using namespace std;
void leadersinarray(int *a, int n){
    int maxelement = a[n-1];
    cout<<maxelement<<"  ";

    for(int i=n-2;i>=0;i--)
    {
        if(maxelement < a[i]){
            maxelement = a[i];
            cout<<maxelement<<"   ";
        }
    }
}
int main()
{
    int n;

    cout<<"Enter the array elements::";
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    leadersinarray(a,n);
    return 0;
}
