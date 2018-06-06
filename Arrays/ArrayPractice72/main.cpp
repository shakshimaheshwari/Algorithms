#include <iostream>
#include <vector>
using namespace std;
void countPairs(int *a, int n)
{
    int left =0, right =0;
    vector<bool> visited(n,false);
    int countPair =0;

    while(right<n)
    {
        while(right<n && !visited[a[right]])
        {
            countPair += right - left;
            visited[a[right]] = true;
            right++;
        }

        while(left < right && (right != n && visited[a[right]]))
        {
            visited[a[left]] = false;
            left++;
        }
    }

    cout<<"The number of distinct pairs is::"<<countPair;
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


    countPairs(a,n);
    return 0;
}
