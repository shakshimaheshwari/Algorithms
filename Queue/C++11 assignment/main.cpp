#include<iostream>
#include<string>
#include<map>

using namespace std;
map<string,string>myMap;
string sortPairsHelper(string &s, int & index){
    index++;
    string result = "";
    int start = index;
    while(index < s.size()){
        if(s[index] == ':'){
            if(s[index+1] == '{'){
                index = index+1;
                return sortPairsHelper(s,index);
            }else{
            string key = s.substr(start, index-start);
            int pos = s.find(',');
            string value = s.substr(index+1, pos-index-1);
            myMap[key] = value;
            index = pos;
            start = index+1;
            }
        }else if(s[index] == '}'){
            index++;
            break;
        }
        index++;
    }
    for(map<string,string>::iterator it = myMap.begin(); it!= myMap.end();it++){
        result+="{" + it->first + "+" + it->second + "}";
    }
    return result;
}
string sortPairs(string &s){
    int index =0;
    return sortPairsHelper(s,index);
}
int main(){
    string s = "{b:{bb: blackberry, cc: cranberry}, a: apple, c: chickoo}";
    string result = sortPairs(s);
    cout<<result;
}
