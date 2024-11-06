https://leetcode.com/problems/palindrome-pairs/description/
// You are given a 0-indexed array of unique strings words.

// A palindrome pair is a pair of integers (i, j) such that:

// 0 <= i, j < words.length,
// i != j, and
// words[i] + words[j] (the concatenation of the two strings) is a 
// palindrome
// .
// Return an array of all the palindrome pairs of words.

// You must write an algorithm with O(sum of words[i].length) runtime complexity.

 

// Example 1:

// Input: words = ["abcd","dcba","lls","s","sssll"]
// Output: [[0,1],[1,0],[3,2],[2,4]]
// Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
// Example 2:

// Input: words = ["bat","tab","cat"]
// Output: [[0,1],[1,0]]
// Explanation: The palindromes are ["battab","tabbat"]
*//LOGIC**
 // we are reversing every word and adding into the trie then we are matching every word in trie if it matches then we store its string number
// which is stored at the end of every string 
 
//  there are 2 cases to handle what if the input word matches with hapf the string in the trie and another is what is trie ended and still
// input word is left which is explained in detail below eg;"lls","s" is s is the input word and trie is s-l-l this will iterate through s 
 // only then we have to check the rest of the trie if it palindrome
 // eg input:bd,dbcc if dbcc is the input word then it check trie for d-b it matches but it reaches end then we have to check the rest
 // of the input word is it palindrome if yes then we mark it as palindrome and store its stringNumber
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    int stringNumber;//this will store the index of the string i.e original words array index of that string
    
    TrieNode(char ch):data(ch),stringNumber(-1){
        for(int i=0;i<26;i++){
            children[i]=0;
        }
    }
};
class Trie{
    TrieNode *root;
    void insertUtil(TrieNode *root,string &word,int i,int &stringNumber){
        if(i>=word.size()){
            root->stringNumber=stringNumber;
            return;
        }
        int index=word[i]-'a';
        if(!root->children[index])
            root->children[index]=new TrieNode(word[i]);
        insertUtil(root->children[index],word,i+1,stringNumber);
    }
    
    

    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(string& word,int &stringNumber){
        insertUtil(root,word,0,stringNumber);
    }
    bool isPalindrome(string &word,int low,int high){
        while(low<=high){
            if(word[low]!=word[high]){
                return false;
            }
                low++;
                high--;
            
        }
        return true;
    }
    void searchCase2(TrieNode*root,vector<int>&myPalindrome,string s){
        if(root->stringNumber!=-1){
            if(isPalindrome(s,0,s.size()-1)){
                myPalindrome.push_back(root->stringNumber);
            }
        }
        for(int i=0;i<26;i++){
            if(root->children[i]!=0){
                s.push_back(i+'a');
                searchCase2(root->children[i],myPalindrome,s);
                s.pop_back();
            }
        }
    }
    void search(string &word,vector<int>&myPalindrome){
        TrieNode* curr=root;
        //Case1:when a prefix of a string word(input),exactly matches with a word in trie 
        //eg:input:bd,dbcc for the second string if we check in trie it
        //will match up util db i.e the prefix of the input word if  the rest
        //of the input string is palindrome than we can say 1,0 is a palindrom
      //Basically there are two cases either there is element are left in trie or input word 
      //It will iterative throught the matching part of the trie and input word
      //and if there is element left in input word below code will run and return 
      //it will iterate the trie until they have matching elements if the input word finished its iterates to next node
      //then the trie will be pointing to next node where palindrom must be checked
      //it will come out of for loop(i.e they have matched all the word but there are still elements in trie)
      //then go into searchCase2 to check if the rest of the trie is palindrome
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->stringNumber!=-1){//this means the input word is still left but the trie has come to an end
                if(isPalindrome(word,i,word.size()-1)){
                    myPalindrome.push_back(curr->stringNumber);
                }
            }
            if(curr->children[index]){
                curr=curr->children[index];
            }else{
                return;
            }
        }
        // Case2:search (input) word is a prefix word in the trie
        //check remainig subtree in the trie for palindrome
        // eg:lls,s trie contains s-l-l (reverse order bcz of logic) s goes to check it maches and there is still elements in that 
      //subtree if the rest is palindrome then it is a palindrome
        searchCase2(curr,myPalindrome,"");
        
        
    }
    
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {//Space Complexit:O(nK) inserting into trie k is the length of word and n is
      //the number of words
        vector<vector<int>>ans;
        Trie trie;
        //insert all words in reverse order and marks its stringNumber
        //as index of wordss array
        for(int i=0;i<words.size();++i){
            auto reverseword=words[i];
            reverse(reverseword.begin(),reverseword.end());
            trie.insert(reverseword,i);
        }
        //find palindromic pairs of each word
        for(int i=0;i<words.size();++i){//O(n*k*k)//k is the length of the word
            vector<int>myPalindrome;//array stores palindromic pair of that word and it can be multiple
            trie.search(words[i],myPalindrome);//O(k*k)//k  for iterating through the length of work and checking palindrone worst caseO(k)            for(auto it:myPalindrome){
                if(it!=i){//same words cannot be added even if they are palindrom
                ans.push_back({i,it});

                }
            }
        }
        return ans;
    }
};
