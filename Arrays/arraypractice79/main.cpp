#include <iostream>
#include <climits>

using namespace std;
void thirdlargest(int *a, int n)
{
    int first = a[0];
    int second = INT_MIN;
    int third = INT_MIN;
    for(int i=1;i<n;i++)
    {
        if(a[i] > first)
        {
            third = second;
            second = first;
            first = a[i];
        }

        else if(a[i]< first && a[i] >second)
        {
            third =second;
            second = a[i];
        }

        else if(a[i] > third)
        {
            third = a[i];
        }
    }

    cout<<"The third largest element is::"<<third;
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

    thirdlargest(a,n);
    return 0;
}
