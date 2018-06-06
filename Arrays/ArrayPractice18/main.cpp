#include <iostream>

using namespace std;
void subarraywithgivensum(int *a, int n, int sum)
{
    int cur_sum = a[0];
    int start =0;
    for(int i=1;i<n;i++)
    {
        while(cur_sum > sum &&start<i-1)
        {
            cur_sum = cur_sum - a[start];
            start++;
        }
        if(cur_sum == sum)
        {
            cout<<"The sum starts from::"<<start<<" to::"<<i-1;
            return;
        }
        cur_sum += a[i];

    }
}
int main()
{
    int n, sum;
    cout<<"Enter the number of items::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the sum which you want to find out::";
    cin>>sum;
    cout<<"Enter the values::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    subarraywithgivensum(a,n, sum);
}
