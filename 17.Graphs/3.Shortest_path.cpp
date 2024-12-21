// class graph {
// 	public:
// 	unordered_map<int, list<pair<int,int> > > adjList;//<node,<neighbour,weight>>

// 	void addEdge(int u, int v, int wt, bool direction) {
// 		//direction = 1 -> undirected graph
// 		//direction => 0 -> directed graph;
// 		adjList[u].push_back({v,wt});
// 		if(direction == 1) {
// 			adjList[v].push_back({u,wt});
// 		}
// 	}

// 	void printAdjList() {
// 		for(auto i: adjList) {
// 			cout << i.first <<"-> ";
// 			for(auto j: i.second) {
// 				cout << "(" << j.first<<", "<<j.second<<"), ";
// 			}
// 			cout << endl;
// 		}
// 	}
*//shortest path using bfs 
  //for bfs we considered weight as one and was undirected
  //in this we traverse using bfs and the first to reach the destination node is the shortest path, and by the help of parent array
  // we find the path we start from destination and check their parents until we reach the end
	void shortestPathBfs(int src, int dest) {
		queue<int> q;
		unordered_map<int,bool> visited;
		unordered_map<int,int> parent;

		//inital steps for src
		q.push(src);
		visited[src] = 1;
		parent[src] = -1;

		while(!q.empty()) {
			int fNode = q.front();
			q.pop();

			for(auto nbr: adjList[fNode]) {
				if(!visited[nbr.first]) {
					q.push(nbr.first);
					visited[nbr.first] = 1;
					parent[nbr.first] = fNode;
				}
			}
		}

		//store path in ans, after traversing in the parent array
		vector<int> ans;
		int node = dest;
		while(node != -1) {
			ans.push_back(node);
			node = parent[node];
		}

		reverse(ans.begin(), ans.end());

		cout << "printing ANs: " << endl;
		for(auto i: ans) {
			cout << i<<", ";
		}
		cout << endl;
		
	}
*//shortest path using dfs
  //1.we are finding topological sort which gives linear ordering and it is present in stack
  //bcz linear ordering gives us the destination nodes dependency i.e the destination is dependent on which all nodes
  //2.for each node in stack update the distance array where the array consits of INT_MAX but one the array[src] containes 0
  //so in distance we are calculating the minimum distance of every node from src
  void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
		
		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour.first] ) {
				topoSortDfs(neighbour.first, visited, ans);
			}
		}

		//while returning, store the node in stack
		ans.push(src);
	}

 	void shortestpathDfs(int dest, stack<int> topoOrder, int n) {
		vector<int> dist(n, INT_MAX);

		int src = topoOrder.top();
		topoOrder.pop();
		dist[src] = 0;


		for(auto nbr: adjList[0]) {
			if(dist[0] + nbr.second < dist[nbr.first]) {
				dist[nbr.first] = dist[0] + nbr.second;
			}
		}		
			

		while(!topoOrder.empty()) {

			int topElement = topoOrder.top();
			topoOrder.pop();

			if(dist[topElement] != INT_MAX) {
				for(auto nbr: adjList[topElement]) {
					if(dist[topElement] + nbr.second < dist[nbr.first]) {
						dist[nbr.first] = dist[topElement] + nbr.second;
					}
				}
			}
		}

		cout << "Printing Ans: " << endl;
		for(int i=0; i<n; i++) {
			cout << i <<"-> " << dist[i] << endl;
		}
		
		
	}
};
// int main() {
// 	graph g;

// 	g.addEdge(6,3,2,1);
// 	g.addEdge(6,1,14,1);
// 	g.addEdge(3,1,9,1);
// 	g.addEdge(3,2,10,1);
// 	g.addEdge(1,2,7,1);
// 	g.addEdge(2,4,15,1);
// 	g.addEdge(4,3,11,1);
// 	g.addEdge(6,5,9,1);
// 	g.addEdge(4,5,6,1);
 

// 	g.printAdjList();

// 	g.shortestDistDijkstra(6,7);

// 	// stack<int> topoOrder;
// 	// unordered_map<int, bool> visited;
// 	// g.topoSortDfs(0, visited, topoOrder);

	

// 	// g.shortestpathDfs(3, topoOrder,5);//for this we are using directed weighted graph
// in this we are finding the distance not path for path we have to take parent array and it is H.W
	
	

// 	// int src = 0;
// 	// // int dest = 4;

// 	// g.shortestPathBfs(src, dest);//for bfs we considered weight as one and was undirected so the above add edge is for 


// 	return 0;
// }
