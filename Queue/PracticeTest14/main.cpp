#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;
map<string,long int>myMap;
class TrieNode{
  bool endOfWord;
  vector<TrieNode*>nextc;
  public:
    TrieNode(){
        endOfWord = false;
        nextc.resize(26);
        for(int i=0;i<26;i++){
            nextc[i] = NULL;
        }
    }
    void insert(string s, int index){
        if(index == s.length()) endOfWord = true;
        else{
            int nextindex = s[index]-'a';
            if(!nextc[nextindex]) nextc[nextindex] = new TrieNode();
            nextc[nextindex]->insert(s,index+1);
        }
    }
};
void preProcessingData(){
     string line;
     TrieNode* trie = new TrieNode();
     ifstream myfile("C:\\Users\\shakshi\\Desktop\\Internship\\SoftwareDevelopment\\word_frequency.tsv");
     if(myfile.is_open()){
        while(getline(myfile, line)){
            istringstream ss(line);
            string word = "";
            long int score;
            ss>>word>>score;
            myMap[word] = score;
            trie->insert(word,0);
        }
        myfile.close();
     }
}
vector<string>top10words(TrieNode* trie){
    vector<string>result;
    auto cmp = [](pair<string,int>&a, pair<string,int>&b){
      return a.second > b.second;
    };
    priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)>relevantresult(cmp);

    if(trie->endOfWord){
        result.push_back()
    }

}
vector<string> searchTop10Results(string& prefix, TrieNode* trie){
    vector<string>result;
    for(int i=0;i<prefix.size();i++){
        int nextindex = prefix[i]-'a';
        if(!trie->nextc[nextindex]) return result;
        else
            trie = trie->nextc[nextindex];
    }
    return top10Words(trie);
}
vector<string>searchData(string prefix){
    preProcessingData();
    TrieNode *trie = new TrieNode();
    return searchTop10Results(prefix, trie);
}
int main() {
	// your code goes here
    searchData("sakshi");
	return 0;
}
