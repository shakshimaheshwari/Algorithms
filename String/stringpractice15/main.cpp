#include <iostream>

using namespace std;
int mincost(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int L[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i == 0 || j ==0)
                L[i][j] =0;

            else if(s1[i-1] == s2[j-1])
                L[i][j] = L[i-1][j-1] +1;

            else
                L[i][j] = max(L[i][j-1], L[i-1][j]);
        }
    }
    return L[n][m];
}
int main()
{
    string s1, s2;
    int costX, costY;
    cout<<"Enter the first string::";
    getline(cin, s1);
    cout<<"Enter the second string::";
    getline(cin, s2);

    int x = mincost(s1, s2);
    cout<<"Enter the value of CostX::";
    cin>>costX;
    cout<<"Enter the value of CostY::";
    cin>>costY;

    cout<<"The minimum cost is::"<<((costX*(s1.length()-x))+(costY*(s2.length()-x)));
    return 0;
}
