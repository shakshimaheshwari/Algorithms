#include <iostream>
#include <string>

using namespace std;
struct Query{
    int first,last;
};
bool isPalindrome(string s1)
{
    for(int i=0, j=s1.length()-1; i<s1.length()/2;i++, j--)
    {
        if(s1[i]!= s1[j])
        {
            return false;
        }
    }
    return true;

}
void queryresultspalindrome(string s1,Query q[], int m)
{
    for(int i=0;i<m;i++)
    {
        int startingpoint = q[i].first;
        int endingpoint = q[i].last;

        string finalcheck = s1.substr(startingpoint,endingpoint-startingpoint+1);
        cout<<finalcheck;
        if(isPalindrome(finalcheck))
        {
            cout<<"The string "<<finalcheck<<" is a palindrome"<<endl;
        }
        else
        {
            cout<<"The string "<<finalcheck<<" is not a palindrome"<<endl;
        }
    }
}
int main()
{
    string s1;
    cout<<"Enter the string::";
    getline(cin, s1);

    Query q[] = {{0,10},{5,8},{2,5},{5,9}};
    int m = sizeof(q)/sizeof(q[0]);

    queryresultspalindrome(s1,q,m);

    return 0;
}
