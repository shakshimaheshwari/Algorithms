#include <iostream>

using namespace std;
void pushzeroestotheend(int *a, int n)
{
    int index =0;
    for(int i=0;i<n;i++)
    {
        if(a[i] ==0)
        {
            index =i;
            break;
        }
    }

    int i=index-1;
    for(int j=i+2;j<n;j++)
    {
        if(a[j] != 0)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    cout<<"The array after the modification is::";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"  ";
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


    pushzeroestotheend(a,n);
    return 0;
}
