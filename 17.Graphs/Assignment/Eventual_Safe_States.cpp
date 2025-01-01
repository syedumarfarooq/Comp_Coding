*//Observation
// 1.if a node, leads to a or enters a cycle in the graph then it is not a safe node
  https://www.geeksforgeeks.org/problems/eventual-safe-states/1
//   A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


  *//logic
  // in this we are using the code of check if a directed graph has cycle using dfs
  // in this when we find a cycle we return true if not while returning we mark that as safe node as bcz it is not leading to a cycle or 
  //contains cycle
  //so basically when we iterate and go to the end and if we find no cycle we return while returning we mark it as a safe node
  //if there is a cycle we return true and wont reach that part of the code which marks it a safe node
*//Conclusion
// in the end if the node is not a part of cycle or will not enter into a cycle path then it is a safe node
*//Code
class Solution {
  public:
    bool checkCyclicDirectedGraphUsingDfs(vector<int> adjList[],int src, unordered_map<int,bool>& visited,
unordered_map<int,bool>&dfsVisited,int safeNodes[]) {

		visited[src] = true;
		dfsVisited[src] = true;//keeping track of recursive call if dfs of any node is called we mark true
        safeNodes[src]=0;
		for(auto nbr: adjList[src]) {
			if(!visited[nbr]) {
				bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(adjList,nbr, visited, dfsVisited,safeNodes);
				if(aageKaAnswer == true)
					return true;
			}
			if(visited[nbr] == true && dfsVisited[nbr] == true) {
				return true;
			}
		}
		
		dfsVisited[src] = false;
		safeNodes[src]=1;//marking the safe node
		return false;
	}
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int,bool>visited,dfsVisited;
        int safeNodes[V]={0};
        for(int i=0;i<V;i++){
            if(!visited[i])checkCyclicDirectedGraphUsingDfs(adj,i,visited,dfsVisited,safeNodes);
        }
        for(int i=0;i<V;i++){
            if(safeNodes[i])ans.push_back(i);
        
        }
        return ans;
    }
};
