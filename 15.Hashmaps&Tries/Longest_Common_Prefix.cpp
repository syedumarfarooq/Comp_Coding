https://leetcode.com/problems/longest-common-prefix/
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
*//LOGIC**
  // if the trienode consist a common prefix then it will start from the same tree and whenever the root has more than 2 children then 
  //it means  the next char will be different for 2 or more strings and even if there is a terminal char this means end of string return
  //so after inserting all the strings we iterate so whenever there are more than 2 children then until then the common prefix is present
class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        children[i] = NULL;
                }
                childCount = 0;
                this->isTerminal = false;
        }
};

class Solution {
public:
    void insertWord(TrieNode* root, string word) {
        
   //base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->childCount++;
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}
void findLCP(string& first,string& ans,TrieNode* root){
    //yha main galti karunga
            if(root->isTerminal) {//if the first string is empty;
                    return;
            }
    for(int i=0;i<first.length();i++){
        char ch=first[i];
        if(root->childCount==1){
            ans.push_back(ch);
            int index=ch-'a';
            root=root->children[index];
        }else{
            break;
        }
        if(root->isTerminal){
            break;//bcz this means a words has reached its end from the trie;
        }
    }
}
string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root=new TrieNode('-');
         //insert strings
        for(int i=0;i<strs.size();i++){
            insertWord(root,strs[i]);
        }
         string ans="";
        string first = strs[0];//does not matter which ever string u compare with as it is common prefix so it should be common in every
 // string
        findLCP(first, ans, root);
        return ans;
        
    }
};
