#include <iostream>
#include <map>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void verticalSumUtil(Node *root, int hD, map<int,int> myMap)
{
    if(root == NULL) return;
    verticalSumUtil(root->left, hD-1, myMap);

    if(myMap.find(hD)!= myMap.end())
    {
        int prevSum = myMap[hD];
        myMap[hD] = prevSum+root->data;
    }
    else
        myMap[hD] = 0;
    /*int prevsum = (myMap.get(hD) == NULL)? 0: myMap.get(hD);
    myMap.put(hD, prevsum+root->data);*/

    verticalSumUtil(root->right, hD+1, myMap);
}
void verticalSum(Node *root)
{
    if(root == NULL)
        return;

    static map<int, int> myMap;
    verticalSumUtil(root, 0, myMap);

    cout<<"Printing~!!";
    map<int, int>:: iterator iter;
    for(iter = myMap.begin(); iter!= myMap.end();iter++){
        cout<<iter->first<< "   "<<iter->second<<endl;
    }

}
void verticalSumMain(Node *root)
{
    verticalSum(root);
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    verticalSumMain(root);
    return 0;
}
