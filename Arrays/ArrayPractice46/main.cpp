#include <iostream>
#include <map>

using namespace std;
void pythagoreantriplet(int *a, int n)
{
    for(int i=0;i<n;i++)
        a[i] = a[i] * a[i];

    map<int, int>myMap;

    for(int i=0;i<n;i++)
    {
        myMap[a[i]] = 1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sq = a[i]+a[j];

            if(myMap.find(sq)!= myMap.end())
            {
                cout<<"Exist";
                return;
            }
        }

    }
    cout<<"Does not exist";
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

    pythagoreantriplet(a,n);
    return 0;
}
