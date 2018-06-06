#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<pair<int, int> > subarraywithzerosum(int *a, int n)
{
    int sum;
    vector<pair<int,int> > out;
    map<int,vector<int> > myMap;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];

        if(sum ==0)
            out.push_back(make_pair(0,i));

        if(myMap.find(sum) != myMap.end())
        {
                vector<int> vc = myMap[sum];
                for(vector<int>::iterator iter = vc.begin(); iter!= vc.end();iter++)
                {
                    out.push_back(make_pair(*iter+1,i));
                }
        }
        myMap[sum].push_back(i);
    }

    return out;
}
void print(vector<pair<int, int> > output)
{
    for(vector<pair<int, int> >::iterator iter = output.begin(); iter != output.end();iter++)
    {
        cout<<"The subarray exist from "<<iter->first<< " to"<<iter->second;
        cout<<endl;
    }
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

    vector<pair<int,int> > output = subarraywithzerosum(a,n);
    if(output.size() == 0)
        cout<<"No subarray exist";
    else
        print(output);
    return 0;
}
