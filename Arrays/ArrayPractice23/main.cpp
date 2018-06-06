#include <iostream>

using namespace std;
void findtwoodd(int *a, int n)
{
    int xor2 = a[0];
    int set_bit_no = 0;
    int x =0, y=0;
    for(int i=1;i<n;i++)
    {
        xor2 = xor2 ^ a[i];
    }

    set_bit_no = xor2 & ~(xor2-1);

    for(int i=0;i<n;i++)
    {
        if(a[i] & set_bit_no)
          x = x^a[i];
        else
          y = y^a[i];
    }

    cout<<"the two numbers are::"<<x<<y;
}
int main()
{
    int n;
    cout<<"Enter the value of n::";
    cin>>n;

    int *a = new int[n];

    cout<<"Enter the values::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    findtwoodd(a,n);
    return 0;
}
