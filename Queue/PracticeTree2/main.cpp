#include <iostream>
#include<string>
#include <stack>

using namespace std;
int calculate(string s){
    if(s.length() == 0) return 0;
    stack<int>nums, ops;
    int rst = 0;
    int num = 0;
    int sign = 1;

    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(isdigit(c)){
            num = num*10 + c-'0';
        }else{
            rst += num*sign;
            num = 0;

            if(c == '+') sign = 1;
            if(c == '-') sign = -1;
            if(c == '('){
                nums.push(rst);
                ops.push(sign);
                rst= 0;
                sign = 1;
            }
            if(c == ')'){
                rst = rst*ops.top() + nums.top();
                ops.pop();
                nums.pop();
            }
        }
    }

    rst+= num*sign;
    return rst;

}

int main()
{
    string s = "(6)-(8)-(7)+(1+(6))";
    int res = calculate(s);
    cout<<res<<endl;
    return 0;
}
