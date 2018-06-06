#include <iostream>
#include <vector>

using namespace std;
void freqUtil(int *a, int low, int high, vector<int>&freq)
{
    if(a[low] == a[high])
    {
        freq[a[low]] += high-low+1;
    }
    else{
        int mid = (low + high)/2;
        freqUtil(a,low,mid,freq);
        freqUtil(a,mid+1,high,freq);
    }
}
void findFrequency(int *a, int n)
{
    vector<int>freq(a[n-1]+1,0);

    freqUtil(a,0,n-1,freq);

    for(int i=0;i<= a[n-1];i++)
        if(freq[i]!=0)
        cout<<"Element "<<i<<":: "<<freq[i];
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


    findFrequency(a,n);

    return 0;
}
