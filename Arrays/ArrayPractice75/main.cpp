#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector< pair<int, int> > subarrayswithzerosum(int *a, int n)
{
    map< int, vector<int> >myMap;

    vector< pair<int, int> > out;

    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum += a[i];

        if(sum == 0)
            out.push_back(make_pair(0,i));

        if(myMap.find(sum) != myMap.end())
        {
            vector<int> vc = myMap[sum];
            for( vector<int>::  iterator it = vc.begin(); it!=vc.end();it++)
                out.push_back(make_pair(*it+1,i));
        }

        myMap[sum].push_back(i);
    }
   return out;
}
void print(vector< pair<int, int> > out)
{
    for (vector< pair<int, int> >::  iterator it = out.begin(); it != out.end(); it++)
        cout << "Subarray found from Index " <<
            it->first << " to " << it->second << endl;
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a  = new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    vector< pair<int, int> > out = subarrayswithzerosum(a,n);

    if(out.size() == 0)
        cout<<"No such subarray exist";
    else
        print(out);
    return 0;
}
