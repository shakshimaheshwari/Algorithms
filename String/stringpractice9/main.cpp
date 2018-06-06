#include <iostream>
#include <string>
#include <map>

using namespace std;
void reversestring(string s1)
{
    int length = s1.length();
    int i=0;
    int j=length;
    while(i<j--)
    {
        char c = s1[i];
        s1[i++] = s1[j];
        s1[j] = c;
    }

    cout<<"The string now is::"<<s1;
    i=0;
    while(s1[i])
    {
        while(s1[i]== ' ')
            i++;

        j=i;
        while(s1[j] && s1[j] != ' ')
            j++;

        int last = j;
        while(i < j--)
        {
            char c = s1[i];
            s1[i++] = s1[j];
            s1[j] = c;
        }

        i = last;
    }

    cout<<"The final string is::"<<s1;
}
int main()
{
    string s1;
    cout<<"Enter the string::";
    getline(cin, s1);
    reversestring(s1);
    return 0;
}
