#include <iostream>
#include <string>
using namespace std;
void areRotations(string s1, string s2)
{
    string temp;
    temp = s1.append(s1);

    if(s1.find(s2)!= string::npos)
        cout<<"Yes rotations of each other";
    else
        cout<<"No";
}
int main()
{
    string s1,s2;
    cout<<"Enter the first string::";
    getline(cin, s1);
    cout<<"Enter the second string::";
    getline(cin,s2);

    areRotations(s1,s2);
    return 0;
}
