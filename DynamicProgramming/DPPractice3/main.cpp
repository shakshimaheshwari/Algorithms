#include <iostream>
#define R 6
#define C 5
using namespace std;
void printMaxSubSquare(bool M[R][C])
{
    int S[R][C];
    for(int i=0;i<R;i++)
        S[i][0] = M[i][0];

    for(int j=0;j<C;j++)
        S[0][j] = M[0][j];


    for(int i=1;i<R;i++)
    {
        for(int j=1;j<C;j++)
        {
            if(M[i][j] == 1)
            {
                S[i][j] = min(S[i][j-1], min(S[j][i-1], S[j-1][i-1]))+1;
            }
                else
                S[i][j] =0;
        }
    }

    int max_of_s = S[0][0];
    int max_i = 0;
    int max_j = 0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(max_of_s < S[i][j])
            {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }

    }

    cout<<"The maximum size sub-matrix conatining all 1's are::";

    for(int i= max_i;i> max_i - max_of_s;i--)
    {
        for(int j= max_j;j> max_j-max_of_s;j--)
        {
            cout<<M[i][j];
        }
    }
}
int main()
{


    bool M[R][C] ={{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};

    printMaxSubSquare(M);
    return 0;
}
