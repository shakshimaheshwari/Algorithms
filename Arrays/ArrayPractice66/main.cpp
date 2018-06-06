#include <iostream>
#include <map>
using namespace std;
void getPairsCount(int *a, int n, int sum)
{
    map<int, int> myMap;
    for(int i=0;i<n;i++)
    {
        myMap[a[i]]++;
    }

    int twice_count =0;
    for(int i=0;i<n;i++)
    {
        twice_count+= myMap[sum-a[i]];

        if(sum - a[i] == a[i])
            twice_count--;
    }

    int result= twice_count/2;

    cout<<"The number of pairs is::"<<result;
}
int main()
{
    int n, sum;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the sum::";
    cin>>sum;
    int *a = new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    getPairsCount(a,n, sum);
    return 0;
}
