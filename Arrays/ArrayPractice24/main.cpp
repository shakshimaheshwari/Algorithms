#include <iostream>

using namespace std;
void subsequenceofsize3(int *a, int n)
{
    int *smaller = new int[n];
    int *larger = new int[n];

    int minimum = 0;
    int maximum = n-1;
    smaller[0] = -1;
    for(int i=1;i<n;i++)
    {
        if(a[i] <= a[minimum])
        {
            minimum = i;
            smaller[i] = -1;
        }
        else
            smaller[i] = minimum;
    }

    larger[n-1] =-1;
    for(int j=n-2;j>=0;j--)
    {
        if(a[j]>= a[maximum])
        {
            maximum =j;
            larger[j] = -1;
        }
        else
            larger[j]=maximum;

    }

    for(int i=0;i<n;i++)
    {
        if(smaller[i]!=-1 && larger[i]!=-1)
        {
            cout<<"The elements are found at"<<a[smaller[i]]<<" "<<a[i]<<" "<<a[larger[i]];
            break;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a= new int[n];

    cout<<"Enter the values::";
    for(int i=0;i<n;i++)
        cin>>a[i];


    subsequenceofsize3(a,n);
    return 0;
}
