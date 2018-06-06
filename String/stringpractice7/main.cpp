#include <iostream>
#include <string>

using namespace std;
void dividestring(string s1, int n)
{
    int length = s1.length();
    if(length%n !=0 )
        cout<<"Cannot be divided into equal parts";

    int part_length = length/n;

    for(int i=0;i<length;i++)
    {
        if(i%part_length == 0)
        {
            cout<<endl;
        }
        cout<<s1[i];
    }
}
int main()
{
    string s1;
    int n;
    cout<<"Enter the string::";
    getline(cin, s1);
    cout<<"Enter the number of parts you want to divide the string into::";
    cin>>n;
    dividestring(s1, n);
    return 0;
}
