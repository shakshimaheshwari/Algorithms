#include <iostream>
#include <queue>
#define R 3
#define C 5
using namespace std;
struct ele{
    int x;
    int y;
};
bool isdelim(ele temp)
{
    if(temp.x == -1 && temp.y == -1)
        return true;
    return false;
}

bool isValid(int x, int y)
{
    if((x<0 && x>R-1) || (y<0 && y>C-1))
        return false;
    return true;
}

bool checkAll(int arr[R][C])
{
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
        if(arr[i][j] == 1)
        return true;
    return false;
}
int rotOranges(int arr[R][C])
{
    queue<ele>q;
    ele temp;
    int ans =0;

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(arr[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                q.push(temp);
            }
        }
    }

    temp.x = -1;
    temp.y =-1;
    q.push(temp);

    while(!q.empty())
    {
        bool flag = false;
        while(!isdelim(q.front()))
        {
            temp = q.front();
            if(isValid(temp.x+1 , temp.y) && arr[temp.x+1][temp.y]==1)
            {
                if(!flag)
                {
                    ans++;
                    flag = true;
                }
                arr[temp.x+1][temp.y] = 2;
                temp.x++;
                q.push(temp);
                temp.x--;

            }

            if(isValid(temp.x, temp.y+1) && arr[temp.x][temp.y+1]==1)
            {
                if(!flag)
                {
                    ans++;
                    flag = true;
                }
                arr[temp.x][temp.y+1] = 2;
                temp.y++;
                q.push(temp);
                temp.y--;
            }

            if(isValid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 1)
            {
                if(!flag)
                {
                    ans++;
                    flag = true;
                }
                arr[temp.x-1][temp.y] = 2;
                temp.x--;
                q.push(temp);
                temp.x++;
            }

            if(isValid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1)
            {
                if(!flag)
                {
                    ans++;
                    flag = true;
                }
                arr[temp.x][temp.y-1] = 2;
                temp.y--;
                q.push(temp);
            }

            q.pop();
        }

    q.pop();
    if(!q.empty())
    {
        temp.x =-1;
        temp.y =-1;
        q.push(temp);
    }
    }
    return (checkAll(arr))?-1:ans;

}
int main()
{
    int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rot\n";
    else
         cout << "Time required for all oranges to rot => " << ans << endl;
    return 0;
}
