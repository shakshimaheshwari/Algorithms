#include <iostream>
#include <map>
using namespace std;
void findelements(int *a , int n, int m)
{
    map<int, int>mapnumber;
    int indexfirst, indexsecond;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        if(mapnumber.find(m-a[i])!= mapnumber.end())
        {
            indexfirst = mapnumber[m - a[i]];
            indexsecond = i;
            flag = true;
            break;
        }

        mapnumber[a[i]] = i;
    }
    if(flag == true)
    {
        cout<<"The index of the numbers is ::"<<indexfirst<<","<<indexsecond;
    }
    else
    {
        cout<<"Such pair does not exist";
    }


}
int main()
{
    int n,m;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a= new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the element for which you want to find the two elements::";
    cin>>m;
    findelements(a,n,m);
    return 0;
}
