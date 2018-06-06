#include <iostream>
#include <stack>
using namespace std;
int countMinReversals(string expr)
{
    int length = expr.length();
    if(length %2 != 0)
        return -1;

    stack<char>s;
    for(int i=0;i<expr.length();i++)
    {

        if(expr[i] == '}' && !s.empty())
        {
            if(s.top() == '{')
             s.pop();
            else
             s.push(expr[i]);
        }
        else
            s.push(expr[i]);
    }

    int red_len = s.size();

    int n =0;

    while(!s.empty() && s.top() == '{')
        {
            s.pop();
            n++;
        }

    return (red_len/2+ n%2);
}
int main()
{
    string expr="}}{{";
    cout<<countMinReversals(expr);
    return 0;
}
