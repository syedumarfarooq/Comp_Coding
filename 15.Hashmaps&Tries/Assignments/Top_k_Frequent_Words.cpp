https://leetcode.com/problems/top-k-frequent-words/
// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

// Example 1:

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:

// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
*//LOGIC****
//   first we add all the words into the trie and add there freequency on the terminal node 
// then we traverse the whole trie and insert into the min heap to find top k frequent words as we are using min heap we add it to the answer
// and reverse the answer 
//   Used min heap because we are keeping the size of heap as k so we if compare the top element and the frequency is greater we add it
// or else we dont as we are comparing with the minimum, if we would have used max heap then we should have compared with the top element which 
// is maximum and every node will be minimum we would have added it and not found k top frequent elements
  //Basically the minimum of the heap should be kth highest frequent word
class comp{
    public:
        bool operator()(const pair<int,string>&a,const pair<int,string>&b){
            return a.first==b.first?a<b:a.first>b.first;  
        }
};
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int freq;
    TrieNode(char ch):data(ch),isTerminal(false){
        for(int i=0;i<26;i++){
            children[i]=0;

        }
        freq=0;
    }
};
class Trie{
    TrieNode *root;
    void insertUtil(TrieNode *root,string &word,int i){
        if(i>=word.size()){
            root->isTerminal=true;
            ++root->freq;
            return;
        }
        int index=word[i]-'a';
        if(!root->children[index])
            root->children[index]=new TrieNode(word[i]);
        insertUtil(root->children[index],word,i+1);
    }
       
        
    
    void traverseUtil(TrieNode *root,string &s,priority_queue<pair<int,string>,vector<pair<int,string>>,comp>&pq,int&k){
        if(!root){
            return;
        }
        if(root->isTerminal){
            if(pq.size()<k){
                pq.push({root->freq,s});
            }
            else if(pq.size()==k&&root->freq>pq.top().first){
                pq.pop();
                pq.push({root->freq,s});
            }
        }
        for(int i=0;i<26;i++){
            if(root->children[i]){
                s.push_back(i+'a');
                traverseUtil(root->children[i],s,pq,k);
                s.pop_back();//backtracking
            }
        }
    }

    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(string word){
        insertUtil(root,word,0);
    }
    void traverse(priority_queue<pair<int,string>,vector<pair<int,string>>,comp>&pq,int&k){
        string s;
        traverseUtil(root,s,pq,k);
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;
        vector<string> ans;
        for(auto word:words){
            trie.insert(word);
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        trie.traverse(pq,k);
        while(!pq.empty()){
            auto top=pq.top();pq.pop();
            ans.push_back(top.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
