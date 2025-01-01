*//Prims algo to find minimum spanning treee
// *//spanning tree
// 1.convert graph to tree
// 2.in tree, every node should be reachable by every other node
*//minimum spanning tree
// spanning tree which has the minimum sum of weights (i.e the edges used to make the tree has weights and that is added that gives the sum
// of the weight in tree)
*//prims algo
// in this we build the tree from scratch to find MST
// to do this we use three datastructures i.e 3 arrays whose size will be equal to number of nodes
// 1.key
//   contains values of each node 
//   in this first value is 0 and rest is intialized with infinity(INT_MAX)
// 2.Mst<bool>
//   tracks which node has been included in MST as of now
//   it is initialized with false 
// 3.parent
//   it stores final structure of mst i.e
//   it stores parent of each node in final MST
//   and is initialized with -1
*//steps
//1.find minimum value's node from key (u) which is not present in mst 
//2.set mst[u]=true
3.get all adjacent nodes of u 
  v=adjacent node
  w=weight of adjacent node
  if(mst[v] == False && w<key[v]){
    key[v]=w
    parent[v]=u;
  }
4.repeat all the steps above until all nodes are added or present in mst (i.e all are true in mst)
*//u can find mst from parent node
https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.
*//code
  class Solution {
  public:
    
    int getMinValueNode(vector<int>&key,vector<int>&mst){
        int temp=INT_MAX;
        int index=-1;//represents the actual node which contains the minimum value
        for(int i=0;i<key.size();i++){
            if(key[i]<temp&&mst[i]==false){
                temp=key[i];
                index=i;
            }
        }
        return index;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<int>key(V,INT_MAX);
        vector<int>mst(V,false);
        vector<int>parent(V,-1);
        key[0]=0;
        while(true){
            //step1;
            int u=getMinValueNode(key,mst);
            if(u==-1)break;
            //step2;
            mst[u]=true;
            //step3; process all adjacent nodes
            for(auto edge:adj[u]){
                int v=edge[0];
                int w=edge[1];
                if(mst[v]==false && w<key[v]){
                    key[v]=w;
                    parent[v]=u;
                }
            }
            
        }
        //sum of mst
        int sum=0;
        for(int u=0;u<parent.size();u++){
            if(parent[u]==-1)continue;
            for(auto edge:adj[u]){//we want the edge where the child and parent are present to extract it weights
              //so we are checking all the edges of childs if the edge node(i.e parent) matches with the parent[u] then we take that
              //weight and add it to sum
                int v=edge[0];
                int w=edge[1];
                if(v==parent[u])
                    sum+=w;
            }
        }
        return sum;
    }
};
