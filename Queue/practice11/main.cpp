#include <iostream>
#include <vector>

using namespace std;
vector<int> minimumnumberofjumps(vector<int>&input)
{
    vector<int>output;
    if(input.size() == 0 || input.size() == 1) return output;
    int k=0; int i=0;
    int maxReach = 0+input[0];
    int steps = 1;
    output.push_back(input[i]);
    while(maxReach < input.size()-1)
    {
        steps++;
        for(int j=i+1;j<=input[i]+i;j++)
        {
            if(maxReach < j+input[j])
            {
                maxReach = j+input[j];
                k = j;
            }
        }
        output.push_back(input[k]);
        i = k;
    }
    cout<<steps<<"  ";
    return output;
}
int main()
{
    vector<int>input;
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        input.push_back(a[i]);
    }
    vector<int>output = minimumnumberofjumps(input);
    for(int i=0;i<output.size();i++)
        cout<<output[i]<<"   ";
    return 0;
}
