#include <iostream>
#define N 5
#define M 4
using namespace std;
bool checkDiagonal(int mat[N][M], int i, int j)
{
    int res = mat[i][j];
    while(++i<N && ++j<M)
    {
        if(mat[i][j] != res)
            return false;
    }
    return true;
}
bool isToeplitz(int mat[N][M])
{
    for(int i=0;i<M;i++)
    {
        if(!checkDiagonal(mat,0,i))
            return false;
    }

    for(int i=0;i<N;i++)
    {
        if(!checkDiagonal(mat,i,0))
            return false;
    }
    return true;
}
int main()
{
    int mat[N][M] =
    {
        { 6, 7, 8, 9 },
        { 4, 6, 7, 8 },
        { 1, 4, 6, 7 },
        { 0, 1, 4, 6 },
        { 2, 0, 1, 4 }
    };

    if(isToeplitz(mat))
    {
        cout<<"The matrix is toeplitz";
    }
    else
    {
        cout<<"The matrix is not toeplitz";
    }
    return 0;
}
