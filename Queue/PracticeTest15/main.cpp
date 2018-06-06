#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <fstream>
using namespace std;
map<string, long int>scoreMap;
class TrieNode{
public:
    map<char,TrieNode> wordChild;
    string value;
    bool endOfWord;

    TrieNode(const string&);
    void add(char);
    string find(const string &);
    void insert(const string&);
    vector<string> top_relevantprefix_words();
    vector<string> searchTop10Records(const string &);
};

TrieNode :: TrieNode(const string &val =""){
    value = val;
    endOfWord = false;
}

void TrieNode::add(char ch){
    if(value == ""){
        wordChild[ch] = TrieNode(string(1,ch));
    }else{
        wordChild[ch] = TrieNode(value+ch);
    }
}

string TrieNode:: find(const string &word){
    TrieNode* root = this;
    for(int i=0;i<word.size();i++){
        const char c = word[i];
        if(root->wordChild.find(c) == root->wordChild.end())
            root->add(c);
        else
            root = &root->wordChild[c];
    }
    return root->value;
}

void TrieNode:: insert(const string &word){
    TrieNode *root = this;
    for(int i=0;i<word.size();i++){
        const char c = word[i];
        if(root->wordChild.find(c) == root->wordChild.end())
            root->add(c);
        else
            root = &root->wordChild[c];
    }
    root->endOfWord = true;
}

vector<string> TrieNode::top_relevantprefix_words(){
    vector<string> result;
    if(endOfWord){
       //cout<<scoreMap[value]<<endl;
       result.push_back(value);
    }
    if(wordChild.size()){
        map<char, TrieNode>::iterator it;
        for(it = wordChild.begin(); it!= wordChild.end(); it++){
            //cout<<it->first;
            vector<string> nodes = it->second.top_relevantprefix_words();
            result.insert(result.end(), nodes.begin(), nodes.end());
        }
    }
    return result;
}

vector<string> TrieNode::searchTop10Records(const string &prefix){
    TrieNode* node = this;
    vector<string>result;
    for(int i=0;i<prefix.size();i++){
        const char c = prefix[i];
        if(node->wordChild.find(c) == node->wordChild.end()){
            return result;
        }else{
            node = &node->wordChild[c];
        }
    }
    result = node->top_relevantprefix_words();
    return result;
}
void preprocessingData(TrieNode* trie){
    string line;
     //TrieNode* trie = new TrieNode();
     ifstream myfile("C:\\Users\\shakshi\\Desktop\\Internship\\SoftwareDevelopment\\word_frequency_1.tsv");
     if(myfile.is_open()){
        while(getline(myfile, line)){
            istringstream ss(line);
            string word = "";
            long int score;
            ss>>word>>score;
            scoreMap[word] = score;
            trie->insert(word);
        }
        myfile.close();
     }
}
int main()
{
    TrieNode *trie = new TrieNode();
    preprocessingData(trie);
    vector<string> result = trie->searchTop10Records("aa");
    cout<<result.size();
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
