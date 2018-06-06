#include <iostream>

using namespace std;
void allpossiblesubarrays(int *a, int *b,int *c,int n, int m, int i, int j, int len,int flag)
{
    if(flag)
    {

        if(len)
        {
            for(int i=0;i<len+1;i++)
                cout<<c[i]<<"  "<<endl;
        }
        for(int k=i;k<n;k++)
        {
            if(!len)
            {
                c[len] = a[k];
                allpossiblesubarrays(a,b,c, n,m,k+1,j,len,!flag);
            }
            else{
                if(a[k] > c[len])
                {
                    c[len+1] = a[k];
                    allpossiblesubarrays(a,b,c,n,m,k+1,j,len+1,!flag);
                }
            }
        }
    }

    else{
        for(int l=j;l<m;l++)
        {
            if(b[l] > c[len])
            {
                c[len+1] = b[l];
                allpossiblesubarrays(a,b,c,n,m,i,l+1,len+1,!flag);
            }
        }
    }



}

void allpossible(int *a, int *b, int n, int m, int flag)
{
    int *c= new int[n+m];
    allpossiblesubarrays(a,b,c,n,m,0,0,0,1);
}
int main()
{
    int n,m;
    int flag =1;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the number of elements for the second array::";
    cin>>m;
    int *a = new int[n];
    int *b = new int[m];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter the elements for array b::";
    for(int i=0;i<m;i++)
        cin>>b[i];


    allpossible(a,b,n,m, flag);
    return 0;
}
