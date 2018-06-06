#include <iostream>
#include <vector>

using namespace std;
int binomialCoeff(int n, int k){
    vector<vector<int> >opt(n+1, vector<int>(k+1, 0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j == 0 || j == i) opt[i][j] =1;
            else opt[i][j] = opt[i-1][j-1] + opt[i-1][j];
        }
    }
    return opt[n][k];
}
int main()
{
    int n;
    int k;
    cout<<"Enter the value of n::";
    cin>>n;
    cout<<"Enter the value of k::";
    cin>>k;
    int x = binomialCoeff(n,k);
    cout<<x<<endl;
    return 0;
}
