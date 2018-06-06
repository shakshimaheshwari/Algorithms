#include <iostream>

using namespace std;
void maxSumNonAdj(int *a, int n)
{
   int excl =0;
   int incl = a[0];
   int excl_new;

   for(int i=1;i<n;i++){
    excl_new = max(excl, incl);
    incl = excl+a[i];
    excl = excl_new;
   }

   int finalsum = max(incl,excl);
   cout<<"The max sum without two elements adjacent::"<<finalsum;
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

    maxSumNonAdj(a,n);
    return 0;
}
