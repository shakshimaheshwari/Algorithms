#include <iostream>

using namespace std;
void segregate(int *a, int n)
{
    int i =0;
    int j = n-1;

    while(i<j){
        while(a[i] == 0 && i<j)
            i++;
        while(a[j] == 1 && j>i)
            j--;

        if(i<j){
            a[i] =0;
            a[j] =1;
            i++;
            j--;
        }
    }

    cout<<"The array after segregation is::";

    for(int i=0;i<n;i++)
        cout<<a[i];
}
int main()
{
    int n;
    cout<<"Enter the array elements::";
    cin>>n;

    int *a = new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    segregate(a,n);
    return 0;
}
