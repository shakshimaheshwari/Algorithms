#include <iostream>
#include <vector>
#include <map>

using namespace std;
void unionandintersection(int *a, int *b, int n, int m)
{
    vector<int>c;
    vector<int>d;
    map<int,int>myMap;
    map<int, int>myMap1;
    cout<<"For the union of the elements"<<endl;

    for(int i=0;i<n;i++)
    {
        c.push_back(a[i]);
        myMap[a[i]] =1;
    }

    for(int j=0;j<m;j++)
    {
      if(myMap.find(b[j])== myMap.end())
      {
          c.push_back(b[j]);
      }
      else
        continue;
    }

    cout<<"The vector of the union of two arrays are::";

    vector<int>::iterator iter;

    for(iter = c.begin();iter!= c.end();iter++)
        cout<<*iter<<"   ";


    cout<<"For the intersection of the elements"<<endl;

    for(int i=0;i<n;i++)
    {
        myMap1[a[i]] = 1;
    }

    for(int j=0;j<n;j++)
    {
        if(myMap1.find(b[j])!= myMap1.end())
        {
            d.push_back(b[j]);
        }
        else
            continue;
    }

    cout<<"The vector for the intersection of two arrays is::";
    vector<int>::iterator it;

    for(it= d.begin();it!= d.end();it++)
        cout<<*it<<"   ";

}

int main()
{
    int n, m;

    cout<<"Enter the number of elements::";
    cin>>n;

    cout<<"Enter the number of elements in array2::";
    cin>>m;


    int *a = new int[n];
    int *b = new int[m];
    cout<<"Enter the elements in array1::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter the elements in array2::";
    for(int i=0;i<m;i++)
        cin>>b[i];

    unionandintersection(a,b,n,m);
    return 0;
}
