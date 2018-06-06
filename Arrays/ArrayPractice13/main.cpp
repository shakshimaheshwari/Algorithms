#include <iostream>

using namespace std;
int getMax(int *a, int n)
{
    int maxele = a[0];
    for(int i=0;i<n;i++)
    {
        if(maxele< a[i])
        {
            maxele = a[i];
        }
    }
    return maxele;
}

int getMin(int *a, int n)
{
    int minele = a[0];
    for(int i=0;i<n;i++)
    {
        if(minele>a[i])
        {
            minele = a[i];
        }
    }
    return minele;
}
bool consecutiveelements(int *a, int n)
{
    int maxelement = getMax(a,n);
    int minelement = getMin(a,n);

    if(maxelement-minelement+1 == n)
    {
        int res = 0;
        for(int i=0;i<n;i++)
        {
            res = res^a[i];
        }

        for(int i = minelement;i<=maxelement;i++)
        {
            res = res^i;
        }
        if(res !=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool flag  = consecutiveelements(a,n);
    cout<<flag;

    return 0;
}
