#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* callFuncAddNumber(ListNode* l1, ListNode* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1 == NULL && l2 == NULL) return l1;
    int carry = 0;
    ListNode *l3 = new ListNode(0);
    ListNode *current = l3;
    while(l1 || l2 || carry){
        l3->val += addTwoDigits((l1)?l1->val : 0 , (l2)?l2->val:0, carry);
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
        if(l1 || l2|| carry){
            l3->next = new ListNode(0);
            l3 = l3->next;
        }
    }
    return current;
}

int addTwoDigits(int a, int b, int &carry){
    int num = a+b + carry;
    if(num > 9){
        carry = num/10;
        num = num%10;
    }else{
        carry = 0;
    }
    return num;
}
int main()
{
    callFuncAddNumber(l1,l2);
    return 0;
}


//Longest Palindromic Subsequence

int longestPalindromicSubseq(string s){
    if(s.length() == 0) return 0;
    vector<vector<int>>opt(s.length(), vector<int>(s.length(),0));

    for(int i=0;i<opt.size();i++){
        opt[i][i] = 1;
    }

    for(int k =2; k<=s.length();k++){
        for(int i=0;i<s.length-k+1;i++){
            int j = i+k-1;
            if(s[i] == s[j]){
                opt[i][j] = 2+ opt[i+1][j-1];
            }else{
                opt[i][j] = max(opt[i+1][j], opt[i][j-1]);
            }
        }
    }
    return opt[0][n-1];
}


//Word break

bool wordBreak(string s, vector<string>& wordDict){
    if(s.length() == 0) return true;
    vector<int>result(s.length()+1, false);
    int max_length = 0;
    int min_length = INT_MAX;
    unordered_set<string>dict(wordDict.begin(), wordDict.end());
    for(auto &word: wordDict){
        int length = word.length();
        max_length = max(max_length, length);
        min_length = min(min_length, length);
    }

    result[0] =  true;

    for(int i=0;i<=s.length();i++){
        for(int j= min_length; j< min(max_length, i);j++){
            if(result[i-j]){
                string word = s.substr(i-j,j);
                if(dict.find(word)!= dict.end()){
                    result[i] = true;
                }
            }
        }
    }

    return result[s.length()];
}


//Sort Characters by Frequency

string frequencySort(string s){
    string result="";
    map<char, int> myMap;

    for(int i=0;i<s.length();i++){
        if(myMap.find(s[i])!= myMap.end()){
            myMap[s[i]]++;
        }else{
            myMap[s[i]] = 1;
        }
    }
    auto cmp =[](pair<char,int>&a, pair<char,int>&b){
        return a.second < b.second;
    };

    priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)>pq(cmp);

    for(int i=0;i<s.length();i++){
        pq.push({s[i],myMap[s[i]]});
    }

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        for(int i=0;i<temp.second;i++){
            result+=temp.first;
        }
    }
    return result;
}

//Rotate Function

int maxRotateFunction(vector<int>&A){
    if(A.size() == 0) return 0;
    int arrSum =0;
    int currSum =0;

    for(int i=0;i<A.size();i++{
        arrSum+=A[i];
        currSum +=A[i];
    }

    int maxVal = currSum;

    for(int j = 1;j<A.size();j++){
        currSum += arrSum - A.size()*A[A.size()-j];
        maxVal = max(maxVal, currSum);
    }
    return maxVal;
}


//Longest Substring without Repeating Characters
int lengthOfLongestSubstring(string s){
    if(s.length() == 0) return 0;
    vector<int>visited(256, 0);
    int max_len = 0;
    int length = 0;
    for(int i=0, start = 0;i<s.length();i++){
        int index = visited[s[i]];
        if(index > start){
            max_len = max(max_len, length);
            length = i- index;
            start = index;

        }
        length++;
        visited[s[i]] = i+1;
    }
}


//Binary Tree Right Side view

 vector<int> rightSideView(TreeNode* root){
     vector<int> result;
     if(root == NULL) return result;

     queue<TreeNode*>q;
     q.push(root);


     while(!q.empty()){
        int size = q.size();
        while(size--){
            int temp = q.front();
            q.pop();
            if(size == 0) result.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }if(temp->right){
                q.push(temp->right);
            }
        }
     }
     return result;
 }



 //Serialize and Deserialize BST
 string serialize(TreeNode* root){
     if(root == NULL){
        return "#";
     }else{
         return to_string(root->val) + "," + serialize(root->left)+ "," + serialize(root->right);
     }
 }

 string deserialize(string data){
     return mydeserialize(data);
 }

 string mydeserialize(string &data){
     if(data[0] == "#"){
        if(data.size()  >1) data = data.substr(2);
        return nullptr;
     }else{
         TreeNode *root = new TreeNode(helper(data));
         root->left = mydeserialize(data);
         root->right = mydeserialize(data);
         return root;
     }
 }

 int helper(string &data){
     int pos = data.find(',');
     int num = stoi(data.substr(0,pos));
     data = data.substr(pos+1);
     return num;
 }


//Validate Binary search Tree
bool isValidBST(TreeNode* root, TreeNode*& prev){
    if(root == NULL) return true;
    if(!isValidBST(root->left, prev)) return false;
    if(prev!= NULL && prev->val >= root->val) return false;
    prev = root;
    return isValidBST(root->right, prev);
}

bool isValidBST(TreeNode* root){
    if(root == NULL) return true;
    TreeNode* prev = NULL;
    return isValidBST(root, prev);
}


//Longest Palindromic Substring

string longestPalindrome(string s){
    if(s.length() == 0)return s;
    vector<vector<int>>opt(s.length(), vector<int>(s.length(),0));

    int start_index =0;
    int max_length = 0;

    for(int i=0;i<s.length();i++){
        opt[i][i] = 1;
        max_length = 1;
    }

    for(int i=0;i<s.length()-1;i++){
        if(s[i] == s[i+1]){
            opt[i][i+1] = 1;
            start_index = i;
            max_length = 2;
        }
    }

    for(int k = 3; k<= s.length(); k++){
        for(int i=0;i<=s.length()-k;i++){
            int j = i+k-1;
            if(s[i] == s[j] && opt[i+1][j-1]){
                opt[i][j] = 1;
                start_index = i;
                max_length = k;
            }
        }
    }

    string s1 = s.substr(start_index, max_length);
    return s1;
}

//convert BST to Greater Tree
int cur_sum =0;
void travel(TreeNode* root){
    if(root == NULL) return;
    if(root->right) travel(root->right);
    root->val += (cur_sum+=root->val);
    if(root->left) travel(root->left);
}
TreeNode* convertBST(TreeNode* root){
    if(root == NULL) return root;
    travel(root);
    return root;
}

//Binary Tree from string
TreeNode* str2tree(string s){
    if(s.length() == 0) return nullptr;

}
