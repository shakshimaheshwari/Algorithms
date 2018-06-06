#include <iostream>

using namespace std;
void maxdiff(int *a, int n){
    int maxelement = a[0];
    int maximumdifference = 0;
    int index =0;
    for(int i=0;i<n;i++)
    {
        if(maxelement < a[i]){
            maxelement = a[i];
            index = i;
        }
    }

    for(int i=0;i<index;i++){
        if(maximumdifference < a[index]-a[i]){
            maximumdifference = a[index]-a[i];
        }
    }
    cout<<"Maximum difference ="<<maximumdifference;
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

    maxdiff(a,n);
    return 0;
}
