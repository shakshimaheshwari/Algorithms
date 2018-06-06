#include <iostream>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;
int myCompare(string x, string y)
{
    string xy = x.append(y);
    string yx = y.append(x);

    return xy.compare(yx)>0?1:0;
}
void biggestnumber(vector<string>a)
{
    sort(a.begin(), a.end(), myCompare);

    cout<<"The largest number is::";
    for(int i=0;i<a.size();i++)
        cout<<a[i];
}
int main()
{
    vector<string> a;
    a.push_back("54");
    a.push_back("546");
    a.push_back("548");
    a.push_back("60");

    biggestnumber(a);
    return 0;
}
