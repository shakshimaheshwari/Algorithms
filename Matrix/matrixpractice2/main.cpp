#include <iostream>
#include <climits>
#define R 12
#define C 10
using namespace std;
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
bool isValid(int i, int j)
{
    if((i<0 && i>R-1) || (j<0 && j>C-1))
        return false;
    return true;
}

bool isSafe(int mat[R][C], int visited[R][C], int i, int j)
{
    if(mat[i][j] == 0 || visited[i][j])
        return false;
    return true;
}
void markUnsafeCells(int mat[R][C])
{
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(mat[i][j] == 0)
                {
                    for(int k=0;k<4;k++)
                    {
                        if(isValid(i+rowNum[k], j+colNum[k]))
                            mat[i+rowNum[k]][j+colNum[k]] = -1;
                    }
                }
            }
        }

        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
        {
            if(mat[i][j] == -1)
                mat[i][j] =0;
        }
}
void findShortestPathUtil(int mat[R][C], int visited[R][C], int i, int j, int &min_dist, int dist)
{
    if(j == C-1)
    {
        min_dist = min(dist, min_dist);
        return;
    }

    if(dist > min_dist)
        return;

    visited[i][j] =1;

    for(int k=0;k<4;k++)
    {
        if(isValid(i+rowNum[k],j+colNum[k]) && isSafe(mat, visited, i+rowNum[k], j+colNum[k]))
        {
            findShortestPathUtil(mat, visited, i+rowNum[k], j+colNum[k], min_dist, dist+1);
        }
    }

    visited[i][j] =0;
}
void findShortestPath(int mat[R][C])
{
    int min_dist = INT_MAX;
    int visited[R][C];

    markUnsafeCells(mat);

    for(int i=0;i<R;i++)
    {
        if(mat[i][0] == 1)
        {
            for(int j=0;j<R;j++)
                for(int k=0;k<C;k++)
                visited[j][k] = 0;

            findShortestPathUtil(mat,visited,i,0,min_dist,0);

            if(min_dist == C-1)
                break;
        }
    }

    if(min_dist != INT_MAX)
        cout<<"The shortest distance is::"<<min_dist;
    else
        cout<<"No such destination exist";
}
int main()
{
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };

    // find shortest path
    findShortestPath(mat);
    return 0;
}
