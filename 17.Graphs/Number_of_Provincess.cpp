https://leetcode.com/problems/number-of-provinces/
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.
// Example 1:
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
*//logic 
//   in this we are using dfs we are iterating through all the nodes and passing the node into dfs and if the graph is connected all the nodes
// will be visited if not count is incremented and returned
//every row determines a node and every column determines a different its neighbours
*//code
  class Solution {
private:
    void dfs(unordered_map<int,bool>&visited,int src,vector<vector<int>>& isConnected){
        visited[src]=true;
        for(int col=0;col<isConnected[src].size();col++){
            if(isConnected[src][col]==1){
                if(!visited[col]){
                    dfs(visited,col,isConnected);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> visited;
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(visited,i,isConnected);
                count++;
            }
        }
        return count;
    }
};
