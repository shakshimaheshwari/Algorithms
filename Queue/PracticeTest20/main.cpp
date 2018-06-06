#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <queue>
using namespace std;
class TrieNode{
public:
    char ch;
    bool endOfWord;
    string val;
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
    TrieNode *trie = new TrieNode('x');
    unordered_map<string, long>countMap;
public:
    void insert(string s);
    vector<pair<string,long>> getWords(string);
    vector<pair<string,long>> searchTop10RelevantWords(vector<string>&);
    void createKeyValuePair(string word, long score);
};

void Trie:: insert(string s){
    TrieNode *p = trie;
    for(int i=0;i<s.length();i++){
        int nextindex = s[i] -'a';
        if(p->nextc[nextindex] == NULL) {
            p->nextc[nextindex] = new TrieNode(s[i]);
        }
        p = p->nextc[nextindex];
    }
    p->val = s;
    p->endOfWord = true;
}

vector<pair<string, long>> Trie::getWords(string prefix){
    vector<string>finalList;
    vector<pair<string,long>> result;
    for(int i=0;i<prefix.size();i++){
        int nextindex= prefix[i] - 'a';
        if(!trie->nextc[nextindex]){
            return result;
        }else{
            trie = trie->nextc[nextindex];
        }
    }
    queue<TrieNode*>q;
    q.push(trie);

    while(!q.empty()){
        TrieNode* first = q.front();
        q.pop();
        if(first->endOfWord){
            finalList.push_back(first->val);
        }
        for(TrieNode* root : first->nextc){
            if(root != NULL){
                q.push(root);
            }
        }
    }
    return searchTop10RelevantWords(finalList);
}

vector<pair<string, long>> Trie::searchTop10RelevantWords(vector<string>&finalList){
    vector<pair<string, long>> result;
    auto cmp = [](pair<string, long>&a, pair<string, long>&b){
        return a.second < b.second;
    };
    priority_queue<pair<string, long>, vector<pair<string, long>>, decltype(cmp)>pq(cmp);

    for(int i=0;i<finalList.size();i++){
        pq.push({finalList[i], countMap[finalList[i]]});
    }
    int size = finalList.size();
    for(int i=0;i<min(10,size); i++){
        auto &top = pq.top();
        result.push_back({top.first, top.second});
        pq.pop();
    }
    return result;
}
void Trie::createKeyValuePair(string word, long score){
    countMap[word] = score;
}
int main()
{
    Trie* trieObject = new Trie();
    string prefix = "";
    cout<<"Enter the prefix for which you want to go for autocomplete::";
    cin>>prefix;
    string line;
     ifstream myfile("C:\\Users\\shakshi\\Desktop\\Internship\\SoftwareDevelopment\\word_frequency.tsv");
     if(myfile.is_open()){
        while(getline(myfile, line)){
                istringstream ss(line);     //For getting the tab separated word and score
                string word = "";
                long score;
                ss>>word>>score;
                trieObject->createKeyValuePair(word, score);
                trieObject->insert(word);
            }
        myfile.close();
    }
    vector<pair<string,long>> result = trieObject->getWords(prefix);
    for(int i=0;i<result.size();i++){
        cout<<result[i].first << "  "<<result[i].second<<endl;
    }
    return 0;
}
