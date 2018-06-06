#include <iostream>
#include <climits>
#include <stack>

using namespace std;
bool canRepresentBST(int *pre1, int n)
{
    stack<int>s;
    int root = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(pre1[i] < root)
            return false;

        while(!s.empty() && s.top() < pre1[i])
        {
            root = s.top();
            s.pop();
        }
        s.push(pre1[i]);

    }
    return true;
}
int main()
{
    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    canRepresentBST(pre1, n)? cout << "true\n":
                              cout << "false\n";

    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2)/sizeof(pre2[0]);
    canRepresentBST(pre2, n)? cout << "true\n":
                              cout << "false\n";
    return 0;
}
