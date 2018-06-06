#include <iostream>
#define MAX 100
using namespace std;
int findK(int a[MAX][MAX], int n, int m, int k)
{
    if(k<=m)
        return a[0][k-1];

    if(k<=(m+n-1))
        return a[k-m][n-1];

    if(k<=(m+n-1+m-1))
        return a[n-1][m-1-(k-(m+n-1))];

    if(k<= (m+n-1+m-1+n-2))
        return a[n-1-(k-(m+n-1+m-1))][0];

    return findK((int(*)[MAX])(&a[1][1]), n-2, m-2, k-(2*n+2*m-4));
}
int main()
{
    int a[MAX][MAX] = {{1, 2, 3, 4, 5, 6},
                       {7, 8, 9, 10, 11, 12},
                       {13, 14, 15, 16, 17, 18}};
    int k = 17;
    cout << findK(a, 3,6,k) << endl;
    return 0;
}
