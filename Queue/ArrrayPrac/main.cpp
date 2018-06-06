#include<iostream>
#include<vector>
using namespace std;
const int SIZE =10;
class Node{
public:
    Node(){}
    Node(int key, int value): key(key),value(value){}
    int key,value;
};

class HashMap{
private:
    vector<Node*>data[SIZE];

public:
    ~HashMap();
    Node* get(int key);
    void put(int key, int value);
    int Hashfn(int value){
        return value%10;
    }
};

Node* HashMap::get(int key){
    int hashkey = Hashfn(key);
    int bucket = hashkey%SIZE;
    for(vector<Node*>::iterator iter = data[bucket].begin(); iter!= data[bucket].end();iter++){
        Node*d = *iter;
        if(d->key == key){
            return d;
        }
    }
    return NULL;
}

void HashMap::put(int key, int value){
    int hashkey = Hashfn(key);
    int bucket = hashkey%SIZE;
    Node *node = this->get(key);
    if(node == NULL){
        data[bucket].push_back(new Node(key,value));
    }
    else
        node->value = value;
}

HashMap::~HashMap(){
    for(int i=0;i<SIZE;i++){
        vector<Node*>&val = data[i];
        for(vector<Node*>::iterator it = val.begin();it!=val.end();it++){
            Node *n =*it;
            delete n;
        }
    }
}
int main(){
    HashMap map;
    cout << "Finding 5: " << map.get(5) << endl;  // -1
    map.put(5, 10);
    map.put(6, 11);
    cout << "Finding 5: " << map.get(5)->value;  // 11
    return 1;
}
