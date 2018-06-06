#include <iostream>
#include<vector>

using namespace std;
vector<int> spiralOrder(int n, int matrix[n][n]) {
        vector<int>result;
        int l=0, h=0;
        int n = matrix.size();
        if(matrix.size() == 0)
        return result;
        int m = matrix[0].size();

        while(l<n && h<m){
        for(int j=0;j<m;j++)
        result.push_back(matrix[l][j]);
        l++;

        for(int i = l; i<n;i++)
        result.push_back(matrix[i][m]);
        m--;

        for(int k = m;k>=0;k--)
        result.push_back(matrix[n][k]);
        n--;

        for(int a = n; a>=0;a--)
        result.push_back(matrix[a][h]);
        h++;
        }
        return result;
}
int main()
{
    int n;
    cin>>n;
    int *matrix = new int[n];
    for(int i=0;i<n;i++)
    *matrix[i] = new int[n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>matrix[i][j];
    spiralOrder(n, matrix);
    return 0;
}
