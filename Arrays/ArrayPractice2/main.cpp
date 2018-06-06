#include <iostream>
#include<map>

using namespace std;
void majorityelement(int *a, int n)
{
    bool flag = false;
    map<int, int>mapmajority;
    for(int i=0;i<n;i++){
        if(mapmajority.find(a[i]) != mapmajority.end()){
            mapmajority[a[i]]++;
        }
        else{
        mapmajority[a[i]] =1;
        }
    }
    map<int,int>::iterator it;
    for(it =  mapmajority.begin(); it != mapmajority.end();it++){
        if(it->second > n/2){
            cout<<"The majority element is::"<<it->first;
            flag = true;
            break;
        }
    }
    if(flag == false){
        cout<<"No such majority element exist";
    }


}
int main()
{
    int n;
    cout<<"Enter the number of elements::";
    cin>>n;

    int *a = new int[n];

    cout<<"Enter the elements::";
    for(int i=0;i<n;i++)
        cin>>a[i];

    majorityelement(a,n);
    return 0;
}
