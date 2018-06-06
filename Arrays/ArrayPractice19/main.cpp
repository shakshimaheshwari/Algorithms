#include <iostream>
#include <map>

using namespace std;
void subarraysumnegativenumbers(int *a, int n , int sum)
{
    int cur_sum =0;
    map<int, int>myMap;
    for(int i=0;i<n;i++)
    {
        cur_sum = cur_sum +a[i];
        if(cur_sum == sum)
        {
            cout<<"Sum found between indexes::"<<0<<"to"<< i<<endl;
            break;
        }
        if(myMap.find(sum-cur_sum)!= myMap.end())
        {
            cout<<"Sum found between indexes::"<<myMap[sum-cur_sum]+1 << "to"<< i<<endl;
            break;
        }

        myMap[cur_sum] = i;

    }

}
int main()
{
    int n, sum;
    cout<<"Enter the number of elements::";
    cin>>n;

    cout<<"Enter the sum which you want to check the existence for::";
    cin>>sum;
    int *a= new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    subarraysumnegativenumbers(a,n,sum);
    return 0;
}
