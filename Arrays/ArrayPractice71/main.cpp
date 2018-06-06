#include <iostream>

using namespace std;
void distinctCount(int *a, int n)
{
    int i=0, j= n-1, sum;
    int countofele =n;

    while(i<j)
    {
        while(i!=j && a[i] == a[i+1])
            countofele--,i++;

        while(i!=j && a[j] == a[j+1])
            countofele--,j--;

        if(i==j)
            break;

        sum = a[i] +a[j];

        if(sum == 0)
        {
            countofele--;
            i++;
            j--;
        }
        else if(sum < 0)
            i++;
        else
            j--;

    }

    cout<<"The count of distinct elements is "<<countofele;
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

    distinctCount(a,n);
    return 0;
}
