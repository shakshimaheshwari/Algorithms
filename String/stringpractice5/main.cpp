#include <iostream>
#include <string>
using namespace std;
string reversestring(string s1)
{
  if(s1.length()==1)
    return s1;
  else
    return reversestring(s1.substr(1,s1.length()-1))+s1.at(0);

}
int main()
{
    string s1;
    cout<<"Enter the string::";
    getline(cin, s1);
    s1  = reversestring(s1);

    cout<<"The reversed string is::"<<s1;
    return 0;
}
