#include <iostream>

using namespace std;

void maximumrepeatingnumber(int *a, int n, int k)
{
    for(int i=0;i<n;i++)
    {
        a[a[i]%k]+=k;
    }

    int maximum = a[0];
    int result =0;
    for(int i=0;i<n;i++)
    {
        if(a[i] >maximum)
        {
            maximum = a[i];
            result = i;
        }

    }

    cout<<"The maximum repeating element is::"<<result;

}

int main()
{
    int n,k;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the  value of k::";
    cin>>k;
    int *a = new int[n];

    cout<<"Enter the values::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    maximumrepeatingnumber(a,n,k);
    return 0;
}
