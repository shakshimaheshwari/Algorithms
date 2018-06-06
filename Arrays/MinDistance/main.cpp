#include <iostream>
#include <climits>

using namespace std;
void minDistance(int *a, int n, int x, int y)
{
    int prev;
    int i=0;
    int minDist = INT_MAX;
    for(i=0;i<n;i++)
    {
        if(a[i] == x || a[i] == y)
        {
            prev = i;
            break;
        }
    }

    for(;i<n;i++)
    {
        if(a[i] == x || a[i] == y)
        {
            if(a[prev] != a[i] &&  minDist> i-prev)
            {
                minDist = i-prev;
                prev = i;
            }
            else
                prev =i;
        }

    }
    cout<<"The minimum distance is::"<<minDist;
}
int main()
{
    int n,x,y;
    cout<<"Enter the number of elements::";
    cin>>n;


    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter the value of x";
    cin>>x;
    cout<<"Enter the value of y:";
    cin>>y;
    minDistance(a,n,x,y);
    return 0;
}
