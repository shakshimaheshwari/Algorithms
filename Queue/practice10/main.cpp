#include <iostream>
#include <vector>

using namespace std;
vector<int> minimumlengthunsortedsubarray(vector<int>&input)
{
    vector<int>output;
    if(input.empty()|| input.size()==1) return output;
    int start  =-1;
    int end = -1;
    for(int i=0;i<input.size()-1;i++)
    {
        if(input[i+1]<input[i])
        {
            start = i;
            break;
        }
    }
    if(start == -1)
    {
        output.push_back(0);
        output.push_back(0);
        return output;
    }
    for(int i=input.size()-1;i>=1;i--)
    {
        if(input[i-1]>input[i])
        {
            end = i;
            break;
        }
    }

    int maximum = input[start];
    int minimum = input[start];
    for(int i=start+1; i<=end;i++)
    {
        maximum = max(maximum,input[i]);
        minimum = min(minimum, input[i]);
    }

    for(int i=0;i<start;i++)
    {
        if(input[i] > minimum){
            start = i;
            break;
        }
    }

    for(int i=input.size()-1;i>end;i--)
    {
        if(input[i]<maximum){
            end = i;
            break;
        }
    }
    output.push_back(start);
    output.push_back(end);
    return output;
}
int main()
{
    vector<int>input;
    vector<int>output;
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        input.push_back(a[i]);
    }

    output = minimumlengthunsortedsubarray(input);
    for(int i=0;i<2;i++)
        cout<<output[i]<<"  ";
    return 0;
}
