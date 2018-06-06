#include <iostream>

using namespace std;
void findSmallest(int *a, int n)
{
    int result =1;
    for(int i=0;i<n && a[i]<= result;i++)
        result = result+a[i];

    cout<<"The smallest path is::"<<result;
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


    findSmallest(a,n);
    return 0;
}
