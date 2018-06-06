#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool findDuplicateparenthesis(string str)
{
    stack<char>s;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == ')')
        {
            char top = s.top();
            s.pop();
            if(top == '(')
                return true;

            else{
                while(top!='(')
                {
                    top = s.top();
                    s.pop();
                }
            }
        }

        else
            s.push(str[i]);
    }
    return false;
}
int main()
{
    string str = "(a+(b)+(c+d))";
    if (findDuplicateparenthesis(str))
        cout << "Duplicate Found ";
    else
        cout << "No Duplicates Found ";
    return 0;
}
