*// Krushkal's Algo for finding minimum spanning tree
*//Steps
// 1.crete a parent data structure with n number of elements where n is total number of nodes
// intialized the data structure with with itself making them individual component
// 2.create a rank array of n size
// and intialize with zero
// 3.convert the adjacency list into linear data structure as(u,v,w) and sorted ,by weights
*//logic
// 1.start algo processing from lowest 'w' edge
// 2.for the lowest w edge u and u find parent for both u,v
// 3.if p1 and p2 are different that means there are in a different component MERGE them
// after merging their parent is decided based on the rank whose ever parents rank is greater they will be made parent amoung the two 
//for both the nodes
// if rank is same any one will be the parent between u,v's parents after making them parent u have to increase the node's rank by 1 who 
// became a parent
//4.if 2 and 3 have parents 1 and 3 and have rank 2 and 0  respectively, as the rank of 1 as parent is more so we have to make 1 as parent
// for both 2 and 3 but the problem is in original graph there is no edge between 3 and 1 so we merge 3 to 2 as 2 has a connection with 1
// but the parent remains 1
// 5.if p1 and p2 are equal ignore
*//CODE
class Solution {
  public:
    
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findParent(parent,parent[node]);//path compression
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
    static bool mycomp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    void getMeEdges(int V,vector<vector<int>> adj[],vector<vector<int>>&edges){
        for(int u=0;u<V;u++){
            for(auto edge:adj[u]){
                int v=edge[0];
                int w=edge[1];
                edges.push_back({u,v,w});
            }
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int>parent(V);
        vector<int>rank(V,0);
        //initializing parent array
        for(int u=0;u<V;u++){
            parent[u]=u;
        }
        vector<vector<int>>edges;
        getMeEdges(V,adj,edges);
        sort(edges.begin(),edges.end(),mycomp);
        int ans=0;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            
            u=findParent(parent,u);
            v=findParent(parent,v);
            if(u!=v){
                unionSet(u,v,parent,rank);
                ans+=w;
            }
        }
        return ans;
    }
};
