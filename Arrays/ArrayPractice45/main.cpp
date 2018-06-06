#include <iostream>

using namespace std;
void printMissing(int *a, int n)
{
    bool missing[100] = {false};
    for(int i=0;i<100;i++)
    {
        if(a[i]< 100)
            missing[a[i]] = true;
    }

    int i=0;
    while(i<100)
    {
        if(missing[i] == false)
        {
            int j = i+1;
            while(j<100 && missing[j] == false)
                j++;

            (i+1 == j)? cout<<i : cout<<i<<"-"<<j-1;

            i = j;
        }
        else
            i++;
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

    printMissing(a,n);
    return 0;
}
