#include <iostream>

using namespace std;
void longestspan(int *a, int *b, int n)
{
    int *auxarray = new int[2*n+1];
    int presum1 =0;
    int presum2 =0;
    int maxLen =0;
    int cur_diff =0;
    for(int i=0;i<2*n+1;i++)
        auxarray[i] =-1;

    for(int i=0;i<n;i++)
    {
        presum1+=a[i];
        presum2+=b[i];

        cur_diff = presum1 - presum2;
        int diffIndex = cur_diff+n;

        if(cur_diff == 0)
            maxLen = i+1;
        else if(auxarray[diffIndex] == -1)
            auxarray[diffIndex] = i;

        else{
            int len = i - auxarray[diffIndex];
            if(len > maxLen)
                maxLen = len;
        }
    }

    cout<<"The maximum length is::"<<maxLen;
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    int *b = new int[n];
    cout<<"Enter the elemnets for array a::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter the elements for array b::";
    for(int i=0;i<n;i++)
        cin>>b[i];

    longestspan(a,b,n);
    return 0;
}
