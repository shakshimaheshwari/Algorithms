#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class TrieNode{
public:
    char ch;
    bool endOfWord;
    string name;
    string ph_no;
    vector<TrieNode*>nextc;
    TrieNode(char c){
        ch = c;
        endOfWord = false;
        nextc.resize(26);
        for(auto &it: nextc){
            it = NULL;
        }
    }
};

class Trie{
private:
    TrieNode *root = new TrieNode('A');
public:
    void insert(string, string);
    vector<pair<string, string>> getNamesWithPhone(string);
};

void Trie::insert(string name, string number){
    TrieNode *current = root;
    for(int i=0;i<name.size();i++){
        int nextindex = name[i] -'a';
        if(!current->nextc[nextindex]) current->nextc[nextindex] = new TrieNode(name[i]);
        current =current->nextc[nextindex];
    }
    current->endOfWord = true;
    current->name = name;
    current->ph_no = number;
}

vector<pair<string,string>> Trie::getNamesWithPhone(string prefix){
    vector<pair<string,string>> result;
    for(int i=0;i<prefix.size();i++){
        int nextindex = prefix[i] -'a';
        if(!root->nextc[nextindex]) return result;
        root = root->nextc[nextindex];
    }

    queue<TrieNode*>q;
    q.push(root);
    while(!q.empty()){
        TrieNode* topName = q.front();
        q.pop();
        if(topName->endOfWord){
            result.push_back({topName->name, topName->ph_no});
        }
        for(TrieNode* trie: topName->nextc){
            if(trie!=NULL){
                q.push(trie);
            }
        }
    }
    return result;
}
int main()
{
    vector<pair<string, string>> input = {
        {"aakash", "9892156789"},
        {"aaditya", "9897234567"},
        {"shakshi", "9004873504"},
        {"shrecha", "9967344003"},
        {"shubham", "9967343464"}
    };
    Trie *trieObject = new Trie();
    for(int i=0;i<input.size();i++){
        trieObject->insert(input[i].first, input[i].second);
    }
    string prefix ="";
    cout<<"Enter the prefix";
    cin>>prefix;
    vector<pair<string, string>> result = trieObject->getNamesWithPhone(prefix);
    for(int i=0;i<result.size();i++){
        cout<<result[i].first <<"  "<<result[i].second<<endl;
    }
    return 0;
}
