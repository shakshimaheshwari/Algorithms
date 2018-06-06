#include <iostream>

using namespace std;
struct Interval
{
    int buy;
    int sell;
};
void buyingsellingtime(int *a, int n)
{
    int countofintervals =0;
    int i=0;
    Interval sol[n/2+1];
    if(n==1)
        return;
    while(i<n-1)
    {
        while(i<n-1 && a[i+1] <= a[i])
            i++;

        if(i == n-1)
            break;

        sol[countofintervals].buy = i++;

        while(i<n && a[i] >= a[i-1])
            i++;

        sol[countofintervals].sell = i-1;

        countofintervals++;
    }

    if(countofintervals == 0)
        cout<<"No such solutions exist";
    else
    {
        for(i=0;i<countofintervals;i++)
            cout<<sol[i].buy<<"   "<<sol[i].sell;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of values::";
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    buyingsellingtime(a,n);
    return 0;
}
