#include <iostream>
#include <string>
#include <stack>
#include<algorithm>

using namespace std;
string removeMatchingPairs(string s)
{
    if(s.length() == 0) return s;
    string result ="";
    stack<char>st;
    st.push(s[0]);
    for(int i=1;i<s.length();i++)
    {
        if(!st.empty()&&((isupper(s[i]) && tolower(s[i])== st.top()) || (islower(s[i]) && toupper(s[i]) == st.top())))
            {
                st.pop();
                continue;
            }
        else
            st.push(s[i]);
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    return
}
int main()
{
    string s;
    getline(cin,s);
    string result = removeMatchingPairs(s);
    cout<<result;
    return 0;
}
