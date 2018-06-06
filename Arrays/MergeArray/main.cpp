#include <iostream>
#define NA -1
using namespace std;


void moveToEnd(int *a, int nplusm){
    int i = nplusm-1;
    for(int j=nplusm-1;j>=0;j--)
        if(a[j] != NA){
            a[i] = a[j];
            i--;
        }
}
void mergeArray(int *a, int *b, int nplusm, int n)
{
    int i = n;
    int j=0;
    int k = 0;

    while(k<(nplusm))
    {
        if((i<nplusm && a[i]<=b[j])||(j == n))
        {
            a[k] = a[i];
            k++;
            i++;
        }
        else{
            a[k] = b[j];
            k++;
            j++;
        }
    }
}
int main()
{
    int nplusm, n;
    cout<<"Enter the n+m array size::";
    cin>>nplusm;
    cout<<"Enter the n array size::";
    cin>>n;

    int a[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
    int *b = new int[n];

    cout<<"Enter the elements of the array n::";
    for(int i=0;i<n;i++)
        cin>>b[i];

    moveToEnd(a,nplusm);
    mergeArray(a,b,nplusm,n);
    cout<<"The array is::";
    for(int i=0;i<nplusm;i++)
        cout<<a[i];
    //mergeArray(a,b,nplusm,n);
    return 0;
}
