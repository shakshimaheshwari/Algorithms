#include <iostream>

using namespace std;
char encodedcharacter(string s1, int k)
{
    string expand;
    string temp;
    int freq =0;
    for(int i=0;i<s1.length();)
    {
        temp ="";
        freq =0;
        while(s1[i]>='a' && s1[i] <= 'z')
        {
            temp.push_back(s1[i]);
            i++;
        }

        while(s1[i]>='0' && s1[i]<='9')
        {
            freq = freq*10 + s1[i]-'0';
            i++;
        }

        for(int j=1;j<=freq;j++)
            expand.append(temp);
    }
    if(freq == 0)
        expand.append(temp);

    return expand[k-1];

}
int main()
{
    string s1;
    int k;
    cout<<"Enter the string::";
    getline(cin,s1);
    cout<<"Enter the value of k::";
    cin>>k;
    char ex = encodedcharacter(s1, k);
    cout<<"The character is::"<<ex;
    return 0;
}
