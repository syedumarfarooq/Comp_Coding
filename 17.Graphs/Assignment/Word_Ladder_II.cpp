https://www.geeksforgeeks.org/problems/word-ladder-ii/1
// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
// Keep the following conditions in mind:

// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList.
// Return an empty list if there is no such transformation sequence.
*//logic 
  // similar to word ladder 1 
  // in this we are storing the sequece of the words and its level 
  // and we do not erase the word from the wordlist after using it we keep it until all the sequence of that level has completely
  // processed then we delete it
  // eg:({hit,hot,dot,dog,cog},5),if we had removed cog after iterating it we could not have got all the possible solution of cog
  // as this ({hit,hot,lot,log,cog},5) is also possible answer and we could have missed it if we had removed it so we dont remove it
*//code
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
       vector<vector<string>> ans;
       queue<pair<vector<string>,int>> q;//vector of string which has all the possible sequence,level
        q.push({{beginWord},1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        int prevLevel=-1;
        vector<string>toBeRemoved;
        while(!q.empty()){
            auto fNode=q.front();
            q.pop();

            auto currSeq =fNode.first;
            string currString=currSeq[currSeq.size()-1];//we take the last word from the sequence and find the next word and checking in wordlist
            int currLevel=fNode.second;
            if(currLevel!=prevLevel){//if the prevlevel and current level are same we do not remove the words from the st
                for(auto s:toBeRemoved)st.erase(s);
                toBeRemoved.clear();
                prevLevel=currLevel;
            }
            //check if we have reached the destination
            if(currString==endWord){//if the last word reaches the endword we store it answer and traverse the other possibilities
                ans.push_back(currSeq);
            }
            for(int index=0;index<currString.length();index++){
              //for every index insert a to z character and check
                char originalChar=currString[index];//as we are changing below we are storing original char 
                for(char ch='a';ch<='z';ch++){
                    currString[index]=ch;
                    //check wordlist
                    if(st.find(currString)!=st.end()){
                       auto temp=currSeq;
                       temp.push_back(currString);
                       q.push({temp,currLevel+1});
                       toBeRemoved.push_back(currString);//we collect all the words to removed and remove it when the level is finished
                    }
                }
                currString[index]=originalChar;
            }
        }
        return ans;
    }
};
