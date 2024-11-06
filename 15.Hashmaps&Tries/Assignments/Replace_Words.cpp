https://leetcode.com/problems/replace-words/description/
// In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

// Return the sentence after the replacement.

 

// Example 1:

// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Example 2:

// Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// Output: "a a b c"
*//logic****
 // we add all the root word inside the trie so that we can check every word of the sentence in the trie if yes then we can replace it
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch):data(ch),isTerminal(false){
        for(int i=0;i<26;i++){
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
        int index=word[i]-'a';
        if(!root->children[index])
            root->children[index]=new TrieNode(word[i]);
        insertUtil(root->children[index],word,i+1);
    }
    bool searchUtil(TrieNode *root,string &word,int&i){
        //whenever we find a terminal node that means we have achieved a root word return that root word index
        if(root->isTerminal){
            return true;
        }
        if(i>=word.size()){
            return root->isTerminal;
        }
        int index=word[i++]-'a';
        
        if(root->children[index]){
            return searchUtil(root->children[index],word,i);
        }
        return false;
    }
    

    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(string word){
        insertUtil(root,word,0);
    }
    int search(string word){
        int i=0;
        bool gotIt=searchUtil(root,word,i);
        return gotIt ? i :-1;
        
    }
    
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie trie;
        
        //insert data into trie
        for(auto root:dictionary){
            trie.insert(root);
        }
        //pick each word and find in trie wether the root is available or not
        int start=0,end=0;
        while(end<sentence.size()){
         //this will check for a space and check root word for that word
            if(sentence[end]==' '||end==sentence.size()-1){
                int len=end==sentence.size()-1?sentence.size():end-start;
                string word=sentence.substr(start,len);
                int trieMatchIndex=trie.search(word);
               cout<<trieMatchIndex<<endl;
                ans+=trieMatchIndex!=-1?word.substr(0,trieMatchIndex):word;
               
                if(sentence[end]==' '){
                    ans+=" ";
                }
                start=end+1;
            }
            ++end;
        }
        return ans;
    }
};
