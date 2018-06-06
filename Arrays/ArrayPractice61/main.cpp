#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printLeast(string a)
{
    int min_avail =1;
    int pos_of_I =0;

    vector<int>v;
    if(a[0] == 'I')
    {
        v.push_back(1);
        v.push_back(2);
        min_avail = 3;
        pos_of_I = 1;
    }

    if(a[0] == 'D')
    {
        v.push_back(2);
        v.push_back(1);
        min_avail =3;
        pos_of_I =0;
    }

    for(int i=1;i<a.length();i++)
    {
        if(a[i] == 'I')
        {
            v.push_back(min_avail);
            min_avail++;
            pos_of_I = i+1;
        }

        else{
            v.push_back(v[i]);
            for(int j= pos_of_I;j<=i;j++)
                v[j]++;

            min_avail++;
        }
    }

    cout<<"The least number is::";
    vector<int>::iterator iter;
    for(iter = v.begin();iter!=v.end();iter++)
        cout<<*iter<<"";
}
int main()
{
    string a;

    cout<<"Enter the input string::";
    cin>>a;

    printLeast(a);
    return 0;
}
