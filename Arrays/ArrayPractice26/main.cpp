#include <iostream>

using namespace std;
void replacewithgreatestelement(int *a, int n)
{
    int maximumelement = a[n-1];
    a[n-1] = -1;

    for(int i=n-2;i>=0;i--)
    {
        int temp = a[i];
        a[i] = maximumelement;

        if(maximumelement < temp)
            maximumelement = temp;

    }

    cout<<"The modified array is::";
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

    replacewithgreatestelement(a,n);
    return 0;
}
