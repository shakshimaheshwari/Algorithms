#include <iostream>

using namespace std;
void frequencieselements(int *a, int n)
{
    for(int i=0;i<n;i++)
        a[i] = a[i]-1;

    for(int i=0;i<n;i++)
        a[a[i]%n] = a[a[i]%n] + n;

    for(int i=0;i<n;i++)
        cout<<(i+1)<<"-->"<<a[i]/n<<endl;
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

    frequencieselements(a,n);
    return 0;
}
