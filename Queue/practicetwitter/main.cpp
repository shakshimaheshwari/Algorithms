#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int> >& matrix) {
         vector<pair<int, int> >zeropair;
         int n = matrix.size();
         int m = matrix[0].size();
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(matrix[i][j] == 0)
                 {
                     zeropair.push_back(make_pair(i,j));
                 }
             }
         }

        for(vector<pair<int, int> >:: iterator iter = zeropair.begin(); iter!= zeropair.end(); iter++)
        {
             int i = iter->first;
             int j = iter->second;
             for(int l = 0;l<n;l++)
                matrix[l][j] = 0;

             for(int k = 0;k<m;k++)
                matrix[i][k] =0;
        }


         cout<<"Matrix::";
         for(int i=0;i<n;i++)
         {
            cout<<endl;
            for(int j=0;j<m;j++)
            {
                cout<<matrix[i][j]<<"   ";
            }
         }


    }


int main()
{
    int n,m;
    vector<vector<int> >matrix;
    vector<int>input;
    vector<int>input1;
    vector<int>input2;
    input.push_back(1);
    input.push_back(2);
    input.push_back(0);
    input1.push_back(2);
    input1.push_back(3);
    input1.push_back(4);
    input2.push_back(5);
    input2.push_back(6);
    input2.push_back(0);
    matrix.push_back(input);
    matrix.push_back(input1);
    matrix.push_back(input2);
    setZeroes(matrix);
    return 0;
}
