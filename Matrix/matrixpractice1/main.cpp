#include <iostream>
#include <queue>
#define M 5
#define N 5
using namespace std;
struct queueNode{
    int i;
    int j;
    int distance;
};
int row[] = {-1, 0, 1, 0};
int col[] = {0, 1, 0, -1};

bool isSafe(int i, int j, char matrix[M][N], int output[M][N])
{
    if(matrix[i][j]!='O' || output[i][j] != -1)
        return false;
    return true;
}

bool isValid(int i, int j)
{
    if((i<0 && i>M-1) || (j<0 && j>N-1))
        return false;
    return true;
}
void findDistance(char matrix[M][N])
{
    int output[M][N];
    queue<queueNode>q;

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            output[i][j] = -1;
            if(matrix[i][j] == 'G')
            {
                queueNode pos = {i,j,0};
                q.push(pos);
                output[i][j] =0;
            }
        }
    }

    while(!q.empty())
    {
        queueNode curr = q.front();
        int x = curr.i;
        int y = curr.j;
        int dist = curr.distance;

        for(int i=0;i<4;i++)
        {
            if(isSafe(x+row[i], y+col[i],matrix, output) && isValid(x+row[i], y+col[i]))
            {
                output[x+row[i]][y+col[i]] = dist+1;
                queueNode que = {x+row[i], y+col[i], dist+1};
                q.push(que);
            }
        }
        q.pop();
    }

    for(int i=0;i<M;i++)
    {
        cout<<endl;
         for(int j=0;j<N; j++)
        {
            cout<<output[i][j]<<"   ";
        }
    }





}
int main()
{
    char matrix[][N] =
    {
        {'O', 'O', 'O', 'O', 'G'},
        {'O', 'W', 'W', 'O', 'O'},
        {'O', 'O', 'O', 'W', 'O'},
        {'G', 'W', 'W', 'W', 'O'},
        {'O', 'O', 'O', 'O', 'G'}
    };

    findDistance(matrix);
    return 0;
}
