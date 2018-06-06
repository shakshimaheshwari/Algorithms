#include <iostream>
#include <vector>
#include <map>
using namespace std;
void unionandintersection(int *a, int *b, int n, int m)
{
    vector<int>num3;
    vector<int> num1;
    map<int, int>mymap1;
    map<int, int>mymap2;

    for(int i=0;i<n;i++)
    {
        mymap1[a[i]] = 1;
    }
    for(int i=0;i<m;i++)
    {
        if(mymap1.find(b[i]) != mymap1.end())
        {
            mymap2[b[i]] = b[i];
        }
        else
            continue;
    }

    for(map<int,int>::iterator iter = mymap2.begin();iter!=mymap2.end();iter++)
    {
        num3.push_back(iter->first);
    }

    cout<<"The intersection of the array is::";
    for(vector<int>::iterator iter = num3.begin(); iter!= num3.end();iter++)
        cout<<*iter;



    //For the union of the two arrays

    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(a[i] <b[j]){
            num1.push_back(a[i]);
            i++;
        }
        else if(b[j]<a[i]){
            num1.push_back(b[j]);
            j++;
        }
        else{
            num1.push_back(a[i]);
            i++;
            j++;
        }
    }
    while(i<n)
    {
        num1.push_back(a[i]);
        i++;
    }

    while(j<m)
    {
        num1.push_back(b[j]);
        j++;
    }
    cout<<"The union of the two arrays is::";
    for(vector<int>::iterator iter = num1.begin();iter!=num1.end();iter++)
        cout<< *iter<< "  ";
}
int main()
{
    int n, m;
    cout<<"Enter the number of elements int first array::";
    cin>>n;
    cout<<"Enter the number of elements in the second array::";
    cin>>m;
    int *a= new int[n];
    int *b = new int[m];
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<m;i++)
        cin>>b[i];
    unionandintersection(a,b,n,m);
    return 0;
}
