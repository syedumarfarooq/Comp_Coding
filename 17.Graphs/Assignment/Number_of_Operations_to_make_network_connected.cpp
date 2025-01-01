https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
*//logic
//   in this we want number of extra edges present in the graph so that we can see if we can use that extra edge to connect all components
  // and number of connected components (i.e how many disjoint componenets) if there are 2 disjoint componenets and there is one extra edge
// we can use that and make connect all nodes into a single component, we need (disjoint components -1) number of extra edges
//if number of extra edges are greater than the cables needed for joining (disjoint components -1) then we return the cable needed for it 
//to be connected or else we return -1 if the number of extra edges are not sufficient then we cannot connect all the components
// 1.extra edges is calculated using krushkal's algo if nodes u and v have same parent then the edge between u and v is extra bcz from u can 
//   reach v without the edge u-v through its parent
//   2.for number of connected compoenents we can find using the krushkal's alogs parent array
//   if the array has a node which is parent of itself then it is a ultimate parent (i.e it is a root node) as that node is not dependent
//   onto any other node or not part of any other component
  *//additional info
  // we can count the  number of connected components (i.e how many disjoint componenets) using dfs but this is a different way
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n);
        vector<int>rank(n,0);
        //initializing parent array
        for(int u=0;u<n;u++){
            parent[u]=u;
        }
        int numExtraEdges=0;
        for(auto connection:connections){
            int u=connection[0];
            int v=connection[1];
            u=findParent(parent,u);
            v=findParent(parent,v);
            if(u!=v){
                unionSet(u,v,parent,rank);
            }else{
                numExtraEdges++;
            }
        }
        int nocc=0;//number of connected components
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                nocc++;
            }
        }
        int ans=nocc-1;//no. of cables needed or no. of operations needed for connecting disjoint components
        return numExtraEdges >= ans ? ans:-1;
    }
};
