#include <iostream>
#include <map>

using namespace std;
void removeduplicates(int *a, int n)
{
    map<int, int>myMap;
    for(int i=0;i<n;i++)
    {
        if(myMap.find(a[i]) == myMap.end())
            myMap[a[i]] = 1;
    }

    map<int, int>:: iterator iter;
    for(iter = myMap.begin(); iter != myMap.end(); iter++)
        cout<<iter->first<<"  ";
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    cout<<"Enter the elements::";
    for (int i=0;i<n;i++)
        cin>>a[i];

    removeduplicates(a,n);
    return 0;
}
