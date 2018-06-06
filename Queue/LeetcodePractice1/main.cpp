#include <iostream>
#include<vector>

using namespace std;
void findAndInvertImage(vector<vector<int>>&A) {
    if(A.size() == 0) return;
    int n = A.size();
    for(int i=0;i<n;i++) {
        for(int j=0, k = n-1;j<=k;j++,k--) {
            if(j == k) {
                A[i][j] = !A[i][j];
            } else {
                A[i][j] = !A[i][j];
                A[i][k] = !A[i][k];
                swap(A[i][j], A[i][k]);
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of rows::";
    cin>>n;
    vector<vector<int>> A(n, vector<int>(n,0));
    cout<<"Enter the array elements::";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>A[i][j];
        }
    }

    findAndInvertImage(A);
    cout<<"Print A::";
    for(int i=0; i< n;i++) {
        cout<<endl;
        for(int j=0;j<n;j++) {
            cout<<A[i][j]<<" ";
        }
    }
    return 0;
}
