#include <iostream>

using namespace std;
void maximumpathsum(int *a, int *b, int n, int m)
{
    int result =0;
    int sum1 =0;
    int sum2 =0;

    int i=0, j=0;

    while(i<n && j<m)
    {
        if(a[i] < b[j])
            sum1+=a[i++];

        else if(a[i] > b[j])
            sum2+=b[j++];

        else{
            result += max(sum1, sum2);
            sum1 =0;
            sum2 =0;

            while(i<n && j<m && a[i] == b[j])
            {
                result = result+ a[i++];
                j++;
            }
        }
    }

    while(i<n)
    {
        sum1 += a[i++];
    }

    while(j<m)
    {
        sum2+= b[j++];
    }

    result += max(sum1, sum2);

    cout<<"The maximum sum path is::"<<result;
}
int main()
{
    int n, m;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the number of elements in the second arary::";
    cin>>m;
    int *a = new int[n];
    int *b = new int[m];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter the elements in array b::";
    for(int i=0;i<m;i++)
        cin>>b[i];

    maximumpathsum(a,b,n,m);

    return 0;
}
