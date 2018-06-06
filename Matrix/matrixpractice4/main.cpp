#include <iostream>
#include <climits>
#define R 3
#define C 10
using namespace std;

struct Pair{
    bool found;
    int value;
};

Pair findLongestPathUtil(int mat[R][C], bool visited[R][C], int i, int j, int x, int y)
{
    if(i==x && j == y)
    {
        Pair p ={true, 0};
        return p;
    }

    if((i<0 || i>R-1) || (j<0 || j>C-1) || mat[i][j] == 0 || visited[i][j])
    {
        Pair p ={false, INT_MAX};
        return p;
    }
    visited[i][j] = true;

    int res = INT_MIN;

    Pair p = findLongestPathUtil(mat,visited,i-1,j,x,y);
    if(p.found)
        res = max(res, p.value);

    p = findLongestPathUtil(mat, visited, i+1,j,x,y);
    if(p.found)
        res = max(res,p.value);

    p = findLongestPathUtil(mat,visited,i,j-1,x,y);
    if(p.found)
        res = max(res, p.value);

    p = findLongestPathUtil(mat, visited, i, j+1, x, y);
    if(p.found)
        res = max(res, p.value);

    visited[i][j] = false;

    if(res != INT_MIN)
    {
        Pair p = {true, 1+res};
        return p;
    }
    else{
        Pair p = {false, INT_MAX};
        return p;
    }
}
void findLongestPath(int mat[R][C], int i, int j, int x, int y)
{
    bool visited[R][C];
    for(int k=0;k<R;k++)
        for(int l=0;l<C;l++)
        visited[k][l] = false;

    Pair p = findLongestPathUtil(mat, visited, i, j, x, y);
    if(p.found)
        cout<<"The destination can be found with the maximum cost of::"<<p.value;
    else
        cout<<"The destination cannot be reached";


}
int main()
{
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };

    // find longest path with source (0, 0) and
    // destination (1, 7)
    findLongestPath(mat, 0, 0, 1, 7);
    return 0;
}
