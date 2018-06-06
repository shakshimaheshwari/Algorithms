#include <iostream>

using namespace std;
void reorderelements(int *a, int *index, int n)
{
    for(int i=0;i<n;i++)
    {
        while(index[i]!=i)
        {
            int oldTargetI = index[index[i]];
            int oldTargetE = a[index[i]];

            a[index[i]] = a[i];
            index[index[i]] = index[i];

            a[i] = oldTargetE;
            index[i] = oldTargetI;
        }
    }


    cout<<"The array after modification is::";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"   ";
}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];
    int *index = new int[n];

    cout<<"Enter the element indexes::";
    for(int i=0;i<n;i++)
        cin>>index[i];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    reorderelements(a,index,n);
    return 0;
}
