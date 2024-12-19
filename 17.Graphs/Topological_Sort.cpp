*//Topological sort
linear ordering of vertices such that for every edge u->v, u comes before v in that ordering
eg:1->2,1->3,2->3
  topological sort:1-2-3
*//Topolocial sort can be implemented using DFS,BFS and can be applied only for Directed Acyclic graph
  //so in the topological sort the dependencies increases as the nodes go further so the first node is independent
  *//u may have question what about disconnected graph
  //in that it does not matter as they both are disconnected both answer can be written in any way as they are not dependent on each other
  // eg:1,2,3 are one graph 4,5,6 are second graph the topological sort can be 1,2,3,4,5,6 or 4,5,6,1,2,3 as they both are independent it does 
// not matter
	*//why only on DAG
	// If a graph contains a cycle, a node would depend on itself (directly or indirectly), making it impossible to find a valid ordering.
	// eg:0-1-2-0 0 is indirectly dependent on itself
  *//using dfs
void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
		
		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour] ) {
				topoSortDfs(neighbour, visited, ans);
			}
		}

		//while returning, store the node in stack//bcz dfs interates to the end and while returning it adds the node bcz it is the most dependent
  // node in the whole graph
		ans.push(src);
	}
int main(){
	// unordered_map<int,bool> visited;
	// stack<int> ans;
	// for(int i=0; i<n; i++) {
	// 	if(!visited[i] ){
	// 		g.topoSortDfs(i,visited,ans);
	// 	}
	// }

	// cout << "Top Sort: " << endl;
	// while(!ans.empty()) {
	// 	cout << ans.top();
	// 	ans.pop();
	// }
}
//The key reason we store the nodes while returning (backtracking) in a topological sort using DFS is because the node being stored at that 
// point is fully processed and all its dependencies (children) have already been visited and stored.
// This ensures that the most dependent nodes are added last to the stack, which is the desired property of a topological sort.
*//to find if a directed graph is cyclic using bsf we use the below method if the answer length != number of nodes then it is cyclic
	// or else acyclic
*//using bfs//kahn's algorithm
  //we push something in queue when they have 0 indegree and once added we remove it from the graph (i.e we just reduce the indegree by 1
  // so the next one becomes 0 degree
  unordered_map<T, list<T > > adjList;
void topoSortBfs(int n, vector<int>& ans) {
		queue<int> q;
		unordered_map<int, int> indegree;

		//indegree calculate
		for(auto i: adjList ) {
			int src = i.first;
			for(auto nbr:i.second) {
				indegree[nbr]++;
			}
		}

		//put all nodes inside queue, which has indegree=0
	//as we are adding all the nodes in the queue with indegree 0 then even if it is disconnected it will be added as indegree 0 for
	//both the components
		for(int i=0; i<n; i++) {
			if(indegree[i] == 0) {
				q.push(i);
			}
		}

		//bfs logic
		while(!q.empty()) {
			int fNode = q.front();
			q.pop();

			ans.push_back(fNode);
			//or we can do count++

			for(auto nbr: adjList[fNode]) {
				indegree[nbr]--;
				//check for zero again
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}	
			}
			
		}
		
	}
int main(){
	// vector<int> ans;
	// //connected or disconnected 
	// g.topoSortBfs(n, ans);

	// if(ans.size() == n) {
	// 	cout << "It is a valid topo sort" << endl;
	// }
	// else {
	// 	cout << "Cycle Present or Invalid topo sort " << endl;
	// }

	
	// cout << "Printing Topological Sort using BFS: " << endl;
	// for(auto i: ans) {
	// 	cout << i << ", ";
	// }cout << endl;
}
*// in Cyclic graph topological sort is never complete i.e it wont have all the node because if there is a cycle all those indegree will be 1
*// and they wont be added
*//so Topolical sort Length != ans.size() in cyclic graph
