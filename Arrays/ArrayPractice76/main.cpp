#include <iostream>
#include <algorithm>
using namespace std;
void minsum(int *a, int n)
{
    sort(a, a+n);

    int c=0, b=0;

    for(int i=0;i<n;i++)
    {
        if(i%2 == 0)
            c = c*10+a[i];
        else
            b = b*10+a[i];
    }

    cout<<"The minimum sum formed::"<<c+b;

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

    minsum(a, n);
    return 0;
}
