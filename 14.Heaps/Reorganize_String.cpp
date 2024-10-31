// Minimum cost to cut the ropes to solve this question too the below pattern or method is used
https://leetcode.com/problems/reorganize-string/description/
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: 
class Node{
    public:
    char data;
    int count;
    Node(char d,int c){
        data=d;
        count=c;
    }
};
class compare{
    public:
    bool operator()(Node a,Node b){
        return a.count<b.count;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        //create mapping
        int freq[26]={0};//we can use map too
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            freq[ch-'a']++;
        }
        priority_queue<Node,vector<Node>,compare> maxHeap;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                Node temp(i+'a',freq[i]);
                maxHeap.push(temp);
            }
        }
        string ans="";
        while(maxHeap.size()>1){
            Node first=maxHeap.top();//we are taking two elements because if we 
            //take one the changes of repeating the same character is high and 
            //we need no two adjacent character same
            maxHeap.pop();
            Node second=maxHeap.top();
            maxHeap.pop();
            ans+=first.data;
            ans+=second.data;
            first.count--;
            second.count--;
            if(first.count!=0){
                maxHeap.push(first);
            }
            if(second.count!=0){
                maxHeap.push(second);
            }
        }
        if(maxHeap.size()==1){
            Node temp=maxHeap.top();
            maxHeap.pop();
            if(temp.count==1){
                ans+=temp.data;
            }else{
                return "";
            }
        }
        return ans;
    }
};
