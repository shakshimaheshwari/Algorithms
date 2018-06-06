#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
class TrieNode{
public:
    bool endOfWord;
    vector<TrieNode*>nextc;
    char ch;

    TrieNode(char c){
        endOfWord = false;
        nextc.resize(26);
        this->ch = c;
        for(auto &it: nextc){
            it = NULL;
        }
    }
};

class Trie{
public:
    TrieNode *root = new TrieNode('A');
    map<string, long int>scoreMap;

    void insert(string word){
        TrieNode* p =root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            int nextindex = word[i]-'a';
            if(p->nextc[nextindex]==NULL){
                p->nextc[nextindex] = new TrieNode(ch);
            }
            p = p->nextc[nextindex];
        }
        p->endOfWord = true;
    }

    vector<string>getWords(string prefix){
        vector<string>finalList;
        for(int k =0 ; k< root->nextc.size(); k++){
            relevantWords(finalList, root->nextc[k],"",prefix);
        }
        return finalList;
    }
    bool startsWith(string &word, string prefix){
        return (word.substr(0, prefix.length()) == prefix);
    }
    vector<string>relevantWords(vector<string>&finalList, TrieNode* local, string word, string prefix){
        if(local){
            word = word+local->ch;
            if(local->endOfWord && startsWith(word, prefix)){
                finalList.push_back(word);
            }
            for(int k=0;k<local->nextc.size();k++){
                relevantWords(finalList, local->nextc[k], word, prefix);
            }
        }
        return finalList;
    }
    void createKeyValuePair(string word, long int score){
        scoreMap[word] = score;
    }

    vector<pair<string,long int> > searchtop10RelevantRecords(vector<string>&finalList){
        vector<pair<string,long int> > result;
        vector<pair<string,long int> > listOfWords;
        for(int i=0;i<finalList.size();i++){
            listOfWords.push_back({finalList[i], scoreMap[finalList[i]]});
        }
        auto mysort = [](pair<string,long int>a, pair<string,long int>b){
            return a.second > b.second;
        };
        sort(listOfWords.begin(), listOfWords.end(), mysort);

        for(int i=0;i<min(10,(int)listOfWords.size());i++){
            result.push_back(listOfWords[i]);
        }
        return result;
    }

};

int main()
{
    Trie* trieObject = new Trie();
    string prefix = "aa";
    string line;
     //TrieNode* trie = new TrieNode();
     ifstream myfile("C:\\Users\\shakshi\\Desktop\\Internship\\SoftwareDevelopment\\word_frequency.tsv");
     if(myfile.is_open()){
        while(getline(myfile, line)){
                istringstream ss(line);
                string word = "";
                long int score;
                ss>>word>>score;
                trieObject->createKeyValuePair(word, score);
                trieObject->insert(word);
            }
        myfile.close();
    }
    //vector<string>listOfWords;
    vector<string> resultList = trieObject->getWords(prefix);
    vector<pair<string, long int> >topRecords = trieObject->searchtop10RelevantRecords(resultList);
    for(int i=0;i<topRecords.size();i++){
        cout<<topRecords[i].first<<" "<<topRecords[i].second<<endl;
    }
    return 0;
}
