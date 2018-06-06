#include <iostream>
#include <stack>
using namespace std;
struct MyStack{

    stack<int>s;
    int minEle;

    void push(int x)
    {
        if(s.empty())
        {
            minEle = x;
            s.push(x);
            cout<<"The number inserted is::"<<x;
            return;
        }
        if(x < s.top())
        {
            s.push(2*x - minEle);
            minEle = x;
        }
        else
            s.push(x);
        cout<<"The number inserted is::"<<x;

    }

    void peek()
    {
        if(s.empty())
        {
            cout<<"No elements left";
            return;
        }

        int t = s.top();
        cout<<"The top elements is::"<<t;
        (t<minEle)? cout<<minEle: cout<<t;
    }

    void getMin()
    {
        if(s.empty())
            cout<<"Stack empty";

        else
            cout<<"The minimum number is the stack is::"<<minEle;

    }

    void pop()
    {
        if(s.empty())
        {
            cout<<"The stack is empty";
            return;
        }

            int t = s.top();
            s.pop();

            if(t < minEle)
            {
                cout<<minEle<<endl;
                minEle = 2*minEle - t;
            }
            else
                cout<<t<<endl;

    }
};
int main()
{

    return 0;
}
