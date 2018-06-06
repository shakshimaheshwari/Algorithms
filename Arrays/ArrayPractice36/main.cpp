#include <iostream>

using namespace std;
void findgroups(int *a, int n)
{
    int countarray[3]={0};
    int i;
    int res=0;
    for(i=0;i<n;i++)
        countarray[a[i]%3]++;

    res+= (countarray[0] * (countarray[0]-1))/2;

    res+= (countarray[1] * countarray[2]);

    res += (countarray[0]* (countarray[0]-1) * (countarray[0]-2))/6;

    res+= (countarray[1]* (countarray[1]-1) * (countarray[1]-2))/6;

    res+= (countarray[2]* (countarray[2]-1) * (countarray[2]-2))/6;

    res+= (countarray[0]*countarray[1]*countarray[2]);

    cout<<"The number of groups are::"<<res;
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

    findgroups(a,n);
    return 0;
}
