#include <iostream>

using namespace std;
void maximumnumberof1s(int *a, int n, int m)
{
    int zerocount =0;
    int Wl=0;
    int Wr =0;
    int bestwindow =0, bestL =0;
    while(Wr <n)
    {
        if(zerocount <= m)
        {
            if(a[Wr] == 0)
                zerocount++;
            Wr++;
        }

        if(zerocount >m)
        {
            if(a[Wl] == 0)
                zerocount--;
            Wl++;

        }

        if(Wr-Wl > bestwindow)
        {
            bestwindow = Wr-Wl;
            bestL = Wl;
        }
    }

   for(int i=0;i<bestwindow;i++)
   {
       if(a[bestL+i] == 0)
        cout<<bestL+i<<"   ";
   }


}
int main()
{
    int n,m;
    cout<<"Enter the number of elements::";
    cin>>n;
    cout<<"Enter the value of m::";
    cin>>m;
    int *a =new int[n];
    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];


    maximumnumberof1s(a,n,m);
    return 0;
}
