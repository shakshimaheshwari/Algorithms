#include <iostream>

using namespace std;
void commonelementsinarray(int *a, int *b, int *c, int n, int m, int o)
{
    int i=0, j=0,k=0;

    while(i<n && j<m && k<o)
    {
        if(a[i] == b[j] && b[j] == c[k])
        {
            cout<<a[i]<<"  ";
            i++; j++; k++;
        }
        else if(a[i] < b[j])
            i++;

        else if(b[j] <c[k])
            j++;

        else
            k++;
    }
}
int main()
{
    int n,m,o;
    cout<<"Enter the number of elements in array1::";
    cin>>n;
    cout<<"Enter the number of elements in array 2::";
    cin>>m;
    cout<<"Enter the number of elements in array3::";
    cin>>o;
    int *a = new int[n];
    int *b = new int[m];
    int *c = new int[o];
    cout<<"Enter the elements in array 1::";
    for(int i=0;i<n;i++)
        cin>>a[i];


    cout<<"Enter the elemnets is array 2::";

    for(int i=0;i<m;i++)
        cin>>b[i];


    cout<<"Enter the elements in array 3::";

    for(int i=0;i<o;i++)
        cin>>c[i];

    commonelementsinarray(a,b,c,n,m,o);
    return 0;
}
