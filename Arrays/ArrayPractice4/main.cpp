#include <iostream>

using namespace std;
int gcd(int n, int d)
{
    if(d == 0)return n;
        else return gcd(d,n%d);
}

void leftrotate(int *a, int n , int d){
    int i,j,k,temp;
    for( i =0;i<gcd(n,d);i++)
    {
        temp = a[i];
        j =i;
        while(1)
        {
            k = j+d;
            if(k>=n)
                k = k-n;
            if(k==i)
                break;
            a[j] = a[k];
            j =k;
        }
        a[j] = temp;
    }
}

void reverseArray(int *a, int start, int e)
{
    int temp;
    while(start<e)
    {
        temp = a[start];
        a[start] = a[e];
        a[e] = temp;
        start++;
        e--;
    }
}
void leftrotatereversalalgo(int *a, int n , int d)
{
    reverseArray(a,0,d-1);
    reverseArray(a,d,n-1);
    reverseArray(a,0,n-1);
}

int main()
{
    int n,d;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the number by which you want to rotate the array::";
    cin>>d;
    gcd(n,d);
    leftrotate(a,n,d);
    leftrotatereversalalgo(a,n,d);
    cout<<"The array after rotation is::";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
