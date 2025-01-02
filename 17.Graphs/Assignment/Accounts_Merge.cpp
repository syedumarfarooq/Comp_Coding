https://leetcode.com/problems/accounts-merge/
// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
// Example 1:

// Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com".
// The third John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

*//logic
// we are considering every account[i] as a node so that we can consider it as disjoint set so that we can perform union set operation
// and merge the accounts who have same email id
// here we are using a map if the email is already present in the map then we mark that account[i] parent as the same parent present in the 
// map and merge them so every email given in the input will have a parent now
// so with the help of parent array which containes the parent of every account we will start putting the emails in a set(ascending order) 
  // to their corresponding parent 
// eg:account["a",1,2]
//           ["b",2,4]
//           ["c",5]
//   as there are three account we will start marking  every email with their account number when we find same email i.e two accounts of same 
// person we have to merge and parent array is updated the "b" account parent is made "a" ("a" and "b" are same person as they have 2 as their 
//   email) for now all the email have their account no and then we start putting all the email inside their respective account in order
//   so we take every account check their parent and put all the emails in that account to their parents account
  //4 initally had "b" as account no. but the parent of that account is "a" so it will be put in "a"
  //so we have only two accounts as "a" and "b" are merged
*//code
class Solution {
public:
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findParent(parent,parent[node]);
      
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(parent,u);
        v=findParent(parent,v);
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }else{
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
         for(int u=0;u<n;u++){
            parent[u]=u;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            auto account=accounts[i];
            for(int j=1;j<account.size();j++){
                string mail=account[j];
                auto it=mp.find(mail);
                if(it==mp.end())mp[mail]=i;//if map does not contain that email then insert it
                else unionSet(i,it->second,parent,rank);//if already exist merge them and update their parents in parent array
              //so if any email of any account is part of any other account we merget that account to the aprent
            }
        }
        unordered_map<int,set<string>>preAns;//set because we want emails in ascending order
        for(auto it:mp){
            auto accountNo=it.second;// account number of that email 
            auto mail=it.first;
            accountNo=findParent(parent,accountNo);//parent account number to store in preAns
          //as some email may have their current account no. and their parent is a different account no. so we find parent of that account 
          // node then place that email into the parent account node
            preAns[accountNo].insert(mail);
        }
        vector<vector<string>>ans;
        for(auto it:preAns){
            auto accountNo=it.first;
            auto st=it.second;
            vector<string>v;
            v.push_back(accounts[accountNo][0]);
            for(auto mail:st) v.push_back(mail);
            ans.push_back(v);
        }
        return ans;
    }

};
