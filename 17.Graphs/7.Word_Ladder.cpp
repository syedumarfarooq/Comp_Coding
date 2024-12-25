https://leetcode.com/problems/word-ladder/
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*//logic
  //we are using bfs as it gives shortest path when we first encounter the destination
// we are creating a queue and pushing the begin word and removing it from the wordlist which is stored in st as we dont want the word to repeat
//this acts like a visited marking where we can only insert the word if it not used we do this by checking the wordlist if it inserted once
// we remove it from the wordlist and from the frontNode we try changing every element of the currString with every character and check
// if anything matches we enter it in the queue
  *//why bfs
  // BFS explores level by level, ensuring that the first time we encounter endWord, it is via the shortest path. This guarantees optimality 
// for unweighted graphs like this word transformation problem.
*//code
  class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {//TC:O(wordlist.length()*length of each word)=>O(n*l)
      //as we are only inserting into the queue if the word is present in the wordList worst case we we have to add all the elements present
      //in the wordList once
        queue<pair<string,int>> q;//currString,countToReachFromBeginWord
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        //which ever word is inserted in the queue we will remove from the set which is wordList
        st.erase(beginWord);
        while(!q.empty()){
            pair<string,int> fNode=q.front();
            q.pop();

            string currString=fNode.first;
            int currCount=fNode.second;
            //check if we have reached the destination
            if(currString==endWord){
                return currCount;
            }
            for(int index=0;index<currString.length();index++){
              //for every index insert a to z character and check
                char originalChar=currString[index];//as we are changing below we are storing original char 
                for(char ch='a';ch<='z';ch++){
                    currString[index]=ch;
                    //check wordlist
                    if(st.find(currString)!=st.end()){
                        q.push({currString,currCount+1});
                        st.erase(currString);
                    }
                }
                currString[index]=originalChar;
            }
        }
        return 0;
    }
};
