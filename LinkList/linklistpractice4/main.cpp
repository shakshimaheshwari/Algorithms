#include <iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;
void alternateSort(list<int>&inp)
{
    inp.sort();
    list<int>::iterator ip = inp.begin();
    ip++;
    for(int i=1;i<(inp.size()+1)/2;i++)
    {
        int val = inp.back();
        inp.pop_back();
        inp.insert(ip,val);
        ++ip;
    }

}
int main()
{
    list<int> inp({1,3,8,2,7,5,6,4});
    alternateSort(inp);

    for(int i:inp)
    {
        cout<<i<<"  ";
    }
    return 0;
}
