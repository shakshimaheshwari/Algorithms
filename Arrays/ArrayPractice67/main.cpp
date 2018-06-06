#include <iostream>

using namespace std;
void countMinOp(int *a, int n)
{
    int result =0;
    int i;
    while(1)
    {
        int zero_count =0;

        for(i=0;i<n;i++)
        {
            if(a[i]%2 ==1)
                break;
            else if(a[i] == 0)
                zero_count++;
        }

        if(zero_count == n)
        {
            cout<<"The result is"<<result;
            return;
        }


        if(i==n)
        {
            for(int i=0;i<n;i++)
                a[i] = a[i]/2;
            result++;
        }

        for(int j=i;j<n;j++)
        {
            if(a[j] %2 == 1)
            {
                a[j]--;
                result++;
            }

        }
    }
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

    countMinOp(a,n);
    return 0;
}
