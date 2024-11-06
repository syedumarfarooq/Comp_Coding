https://leetcode.com/problems/camelcase-matching/description/
// Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if queries[i] matches pattern, and false otherwise.

// A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query. You may insert each character at any position and you may not insert any characters.

 

// Example 1:

// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
// Output: [true,false,true,true,false]
// Explanation: "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
// "FootBall" can be generated like this "F" + "oot" + "B" + "all".
// "FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
// Example 2:

// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
// Output: [true,false,true,false,false]
// Explanation: "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
// "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
*//Logic****
  we are adding the pattern inside the trie and then passing the queries one by one if there are any lowercase in between we are only
iterating i we are not moving the root then when there is a capital letter then if it matches the trie then only we are moving forward
class TrieNode{
    public:
    char data;
    TrieNode *children[58];
    bool isTerminal;
    TrieNode(char ch):data(ch),isTerminal(false){
        for(int i=0;i<58;i++){
            children[i]=0;
        }
    }
};
class Trie{
    TrieNode *root;
    void insertUtil(TrieNode *root,string &word,int i){
        if(i>=word.size()){
            root->isTerminal=true;
            return;
        }
        int index=word[i]-'A';
        if(!root->children[index])
            root->children[index]=new TrieNode(word[i]);
        insertUtil(root->children[index],word,i+1);
    }
    bool searchUtil(TrieNode *root,string &word,int i){
        
        
        if(i>=word.size()){
            return root->isTerminal;
        }
        int index=word[i]-'A';
        if(root->children[index]){
            return searchUtil(root->children[index],word,i+1);
        
        }//if lower skip all the small letter and keep the root there itself
        else if(islower(word[i])){
            return searchUtil(root,word,i+1);
        }
        return false;
    }
    

    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(string& word){
        insertUtil(root,word,0);
    }
    bool search(string& word){
    
        return searchUtil(root,word,0);
        
        
    }
    
};
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        Trie trie;
        trie.insert(pattern);
        for(auto query:queries){
            ans.push_back(trie.search(query));

        }
        return ans;
    }
};
