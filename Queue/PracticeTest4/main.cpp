#include <iostream>
#include <string>

using namespace std;
string helper(string s, int &i){
        string res;

        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';

                i++; // '['
                string t = helper(s, i);
                i++; // ']'

                while (n-- > 0)
                    res += t;
            }
        }

        return res;
    }
    string decodeString(string s) {
        if(s.length() == 0) return s;
        int i=0;
        return helper(s, i);
    }
int main()
{
    string s = "3[a]2[bc]";
    string result = decodeString(s);
    cout<<result;
    return 0;
}
