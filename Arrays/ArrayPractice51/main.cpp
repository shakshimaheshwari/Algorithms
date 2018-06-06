#include <iostream>

using namespace std;
void zigzag(int *a, int n, int flag)
{
    for(int i=0;i<=n-2;i++)
    {
        if(flag)
        {
            if(a[i] > a[i+1])
                swap(a[i], a[i+1]);
        }
        else
        {
            if(a[i] < a[i+1])
                swap(a[i],a[i+1]);
        }

        flag = !flag;
    }

    cout<<"The modified array in the zigzag position is::";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"  ";
}
int main()
{
    int n;
    int flag =1;
    cout<<"Enter the elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    zigzag(a,n,flag);
    return 0;
}
