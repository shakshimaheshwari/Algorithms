#include <iostream>
#include<stack>
#include<algorithm>

using namespace std;
struct Interval
{
    int starttime;
    int endtime;
};
int compareStartTime(Interval i1, Interval i2)
{
    return (i1.starttime < i2.starttime);
}
void mergeIntervals(Interval arr[], int n)
{
    if(n<=0)
        return;

    stack<Interval>s;

    sort(arr, arr+n, compareStartTime);

    s.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        Interval top = s.top();
        if(top.endtime < arr[i].starttime)
            s.push(arr[i]);

        else if(top.endtime> arr[i].starttime)
        {
            top.endtime = arr[i].endtime;
            s.pop();
            s.push(top);
        }
    }

    cout<<"The merged intervals are::";
    while(!s.empty())
    {
        Interval t = s.top();
        cout<<"[ "<< t.starttime<<" , "<<t.endtime<<"]";
        s.pop();
    }
}
int main()
{
    Interval arr[] = { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr,n);
    return 0;
}
