/****************************************APPLE HOMEWORK*************************************************************/
/* Problem Description: Given a tab separated file having phrase and popularity of that phrase. Develop an API that
                        accepts a prefix and return the Top 10 phrases for the given prefix
    Input: A tab separated file and a function taking prefix as the argument
    Output: List of top 10 phrases for the given prefix
*/
/*******************************************************************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
/******************************************CLASS TRIENODE************************************************************/
    /* Class :      TrieNode
    Description:  Provides a boilerplate to define the contents of a TrieNode

    Class Variables: bool endOfWord(Consists of a marker that helps to define the end of the word)
                    char ch (Have a character value to mark the character that is stored in the node)
                    vector<TrieNode*>nextc (Have a list of 26 TrieNodes that is used to mark the index of the next character)
    Member functions: A constructor for resizing initializing the values to the class variables
    */
/********************************************************************************************************************/
class TrieNode{
public:
    bool endOfWord;
    vector<TrieNode*>nextc;
    char ch;
    string wordStored;
    TrieNode(char c){
        endOfWord = false;
        nextc.resize(26);
        this->ch = c;
        for(auto &it: nextc){
            it = NULL;
        }
    }
};
/*********************************************END CLASS TRIENODE**********************************************************/
/*********************************************CLASS TRIE******************************************************************/
    /*Class :   Trie
    Description : Provides all the major functionality for retrieving the top 10 results
    Class Variables: Have an instantiated variable of the class Trie
                    Have a map for holding the word and the score that has been fetched from the file during preprocessing
    Member functions: 1. Insert(): for inserting into the trie
                        2. getWords(): for getting words starting with a given prefix
                        3. createKeyValuePair(): For storing the word and its score in the unordered_map
                        4. searchTop10RelevantRecords() : For returning the top 10 phrases from the result list
    */
/*************************************************************************************************************************/
class Trie{

    TrieNode *root = new TrieNode('A');
    unordered_map<string, long>scoreMap;
public:
    void insert(string);
    vector<pair<string,long>>getWords(string);
    bool startsWith(string& ,string);
    vector<string>relevantWords(vector<string>&, TrieNode*, string, string);
    void createKeyValuePair(string, long);
    vector<pair<string,long>>searchtop10RelevantRecords(vector<string>&);
};
/**********************************************INSERT FUNCTION*****************************************************************/
    /*  Function Signature: void insert(string)
        Input: string
        Output: void
        Description: To insert the word in a Trie Structure
    */
/******************************************************************************************************************************/
    void Trie:: insert(string word){
        TrieNode* current =root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            int nextindex = word[i]-'a';
            if(current->nextc[nextindex]==NULL){
                current->nextc[nextindex] = new TrieNode(ch);
            }
            current = current->nextc[nextindex];
        }
        current->endOfWord = true;
        current->wordStored = word;
    }
/*******************************************GETWORDS FUNCTION**************************************************************/
    /*  Function Signature: vector<string> getWords(string prefix)
        Input: string prefix
        Output: vector<pair<string,long>>
        Description: returns a list of top 10 relevant words that start with the given prefix with the help of the helper function
                     searchtop10RelevantRecords()
    */
/**************************************************************************************************************************/
    vector<pair<string,long>> Trie::getWords(string prefix){
        vector<string>finalList;
        vector<pair<string,long>> result;
        for(int i=0;i<prefix.length();i++){
            int nextindex = prefix[i]-'a';
            if(!root->nextc[nextindex]){
                return result;
            }
            root = root->nextc[nextindex];
        }

        queue<TrieNode*>relevantqueue;
        relevantqueue.push(root);
        while(!relevantqueue.empty()){
            TrieNode* first = relevantqueue.front();
            relevantqueue.pop();
            if(first->endOfWord){
                finalList.push_back(first->wordStored);
            }
            for(TrieNode* temp : first->nextc){
                if(temp!=NULL){
                    relevantqueue.push(temp);
                }
            }
        }
        return searchtop10RelevantRecords(finalList);
    }

/**********************************CREATEKEYVALUEPAIR FUCNTION**************************************************************/
/*  Function signature: void createKeyValuePair(string, long int)
    Input:  string word: the word that has been taken from tab separated file
            long int score: the relevant popularity score
    Output: void
    Description: Stores the word and its corresponding score in the unordered_map with word as the key and score as the value
    */
/***************************************************************************************************************************/
    void Trie::createKeyValuePair(string word, long score){
        scoreMap[word] = score;
    }

/**************************************SEARCHTOP10RELEVANTRECORDS FUNCTION**************************************************/
/*  Function Signature: vector<pair<string,long>> searchtop10RelevantRecords(vector<string>&)
    Input: vector<string>&finalList: for feeding the relevant results that starts with the given prefix
    Output: vector<pair<string,long>>
    Description: To give out the top 10 relevant results along with its score
    Additional Information: Priority queue has been used in order to sort the results on the basis of the popularity score
    */
/***************************************************************************************************************************/
    vector<pair<string,long> > Trie::searchtop10RelevantRecords(vector<string>&finalList){
        vector<pair<string,long> > result;
        auto prioritysort = [](pair<string,long>&a, pair<string,long>&b){
            return a.second < b.second;
        };
        priority_queue<pair<string, long>, vector<pair<string, long>>, decltype(prioritysort)>relevantWordsQueue(prioritysort);
        for(int i=0;i<finalList.size();i++){
            relevantWordsQueue.push({finalList[i], scoreMap[finalList[i]]});
        }
        int sizeofQueue = relevantWordsQueue.size();
        int k = 10;
        while(!relevantWordsQueue.empty() && k > 0){
            auto &topWord = relevantWordsQueue.top();
            result.push_back({topWord.first, topWord.second});
            relevantWordsQueue.pop();
            k--;
        }
        return result;
    }

int main()
{
    Trie* trieObject = new Trie();
    string prefix="";
    cout<<"Enter the prefix which you want to search top 10 words for::";
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
    vector<pair<string, long> >topRecords = trieObject->getWords(prefix);
    for(int i=0;i<topRecords.size();i++){
        cout<<topRecords[i].first<<" "<<topRecords[i].second<<endl;
    }
    return 0;
}
