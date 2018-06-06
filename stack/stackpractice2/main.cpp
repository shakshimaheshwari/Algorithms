#include <iostream>
#include <queue>

using namespace std;
class Stack{
    queue<int>q;

public:
    void push(int);
    void pop();
    int top();
    bool emptyqueue();
};


void Stack::push(int value)
{
    int s = q.size();
    q.push(value);

    for(int i=0;i<s;i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
}
void Stack::pop()
{
    if(q.empty())
        cout<<"No elements::";
    else
        q.pop();
}

int Stack::top()
{
    return(q.empty())?-1: q.front();
}
bool Stack::emptyqueue()
{
    return (q.empty());
}
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    s.pop();
    cout << s.top() << endl;
    return 0;
    return 0;
}
