#include <iostream>

using namespace std;
int smallestmissing(int *a, int start, int last)
{
        if(start > last)
            return last+1;
        if(start != a[start])
            return start;

        int mid = start+last/2;

        if(a[mid]>mid)
            return smallestmissing(a,start, mid);
        else
            return smallestmissing(a,mid+1,last);
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

    int number = smallestmissing(a,0,n-1);

    cout<<"The smallest number is::"<<number;
    return 0;
}
