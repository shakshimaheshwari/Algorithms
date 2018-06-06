#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string largesttime(vector<int>&input)
{
    string result="";
    sort(input.begin(), input.end());
    if(input[0]>2) return "Not possible";
    int index = -1;
    for(int i=0;i<input.size();i++)
    {
        if(input[i] == 2)
        {
            index = i;
            break;
        }
    }

    if(index == 0)
    {
        result+=(input[index]+'0');
        if(input[1]>=4) return "Not possible";
        else {
            if(input[3]>=4 && input[2]>=4)
            {
                result+=(input[1] +'0');
                result+=":";
                if(input[2]>= 6)return "Not possible";
                else{
                    if(input[3]<6){
                        result+=(input[3]+'0');
                        result+=(input[2]+'0');
                    }
                    else {
                        result+=(input[2]+'0');
                        result+=(input[3]+'0');

                    }
                    return result;
                }
            }
            else if(input[3]>=4 && input[2]<4)
            {
                result+=(input[2]+'0');
                result+=":";
                if(input[3]>=6){
                    result+=(input[1]+'0');
                    result+=(input[3]+'0');
                }
                else{
                    result+=(input[3]+'0');
                    result+=(input[1]+'0');
                }
                return result;
            }
            else{
                result+=(input[3]+'0');
                result+=":";
                if(input[2]>=6){
                    result+=(input[1]+'0');
                    result+=(input[2]+'0');
                }
                else{
                    result+=(input[2]+'0');
                    result+=(input[1]+'0');
                }
                return result;
            }
        }



    }
    else if(index == 3)
    {
        result+=(input[index]+'0');
        result+=(input[2]+'0');
        result+=":";
        result+=(input[1]+'0');
        result+=(input[0]+'0');
        return result;
    }
    else if(index == 1)
    {
        if(input[2]>=4 && input[3]>=4){
            result+=(input[0]+'0');
            result+=(input[3]+'0');
            result+=":";
            if(input[2]>=6){
                result+=(input[1]+'0');
                result+=(input[2]+'0');
            }
            else{
                result+=(input[2]+'0');
                result+=(input[1]+'0');
            }
            return result;
        }
        else if(input[2]<4){
            result+=(input[1]+'0');
            result+=(input[2]+'0');
            result+=":";
            if(input[3]>=6){
                result+=(input[0]+'0');
                result+=(input[3]+'0');
            }
            else{
                result+=(input[3]+'0');
                result+=(input[0]+'0');
            }
            return result;
        }
    }
    else if(index == 2)
    {
        result+=(input[index]+'0');
        if(input[3]>=4){
            result+=(input[1]+'0');
            result+=":";
            if(input[3]>=6){
                result+=(input[0]+'0');
                result+=(input[3]+'0');
            }
            else{
                result+=(input[3]+'0');
                result+=(input[0]+'0');
            }
         return result;
        }
        else{
            result+=(input[3]+'0');
            result+=":";
            result+=(input[1]+'0');
            result+=(input[0]+'0');
        }
        return result;
    }
    else
    {
        int index1 = -1;
        for(int i=0;i<input.size();i++)
        {
            if(input[i] == 1)
            {
                index1 = i;
            }
        }
        if(index1 == 0){
            result+=(input[index1]+'0');
            result+=(input[3]+'0');
            result+=":";
            if(input[2]>=6){
                result+=(input[1]+'0');
                result+=(input[2]+'0');
            }
            else{
                result+=(input[2]+'0');
                result+=(input[1]+'0');
            }
            return result;
        }
        else if(index1 == 3){
            result+=(input[index1]+'0');
            result+=(input[2]+'0');
            result+=":";
            result+=(input[1]+'0');
            result+= (input[0]+'0');
            return result;
        }
        else{
            int index0 = -1;
            for(int i=0;i<input.size();i++)
            {
                if(input[i] == 0)
                {
                    index0 = i;
                }
            }
            if(index0 == 3){
                result+=(input[index0]+'0');
                result+=(input[2]+'0');
                result+=":";
                result+=(input[1]+'0');
                result+=(input[0]+'0');
                return result;
            }
        }
    }
    return result;
}
int main()
{
    int a, b,c,d;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    vector<int>input;
    input.push_back(a);
    input.push_back(b);
    input.push_back(c);
    input.push_back(d);
    string result = largesttime(input);
    cout<<result<<endl;
    return 0;
}
