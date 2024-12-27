*//Handles Negative Weights:
// Unlike Dijkstra's Algorithm, Bellman-Ford works with graphs that have edges with negative weights.as dijkstra's fails in some cases
// This is useful in scenarios like currency exchange or situations with "penalty" costs.
*//Detects Negative Weight Cycles:
// It can identify if a graph contains a negative weight cycle (a cycle where the total weight is negative), which is crucial in certain applications.

*//why n-1 times relaxation where relaxation means for any two node u,v if (d[u]+c(u,v)<d[v])=>d[v]=d[u]+c(u,v)
// eg:a-b-c-d here let us assume every char as every level which has multiple vertices, here we have to do n-1 relaxations, in end of first pass 
// the  optimal solution from a-b will be found ,that also means the c level might not have the optimal solution as c must have been updated
// before b becoming optimal this all depends on the order in which edges are traversed, for that in second pass from b to c as at the end of
// first pass b has optimised value then c can be updated based on b value
// and same with c to d 
// eg:a-b :6
//   b-d:-1
//   a-c:5
//   c-b:-2
  //in first pass a,b,c,d will have 0,3,5,5 i.e if we go in above order
  //in second pass a,b,c,d will have 0,3,5,2 here d value is changed that is second pass i.e the second level
//so atmost it can update its distance  n-1 times
  *//chatgpt answer
// Imagine you have a graph, and you're trying to find the shortest path from a starting point to all other points.

// In the first pass, the algorithm checks the shortest paths that use 1 edge (the direct connections) i.e 0 to all its neighbor.
// In the second pass, it looks at paths that use 2 edges (going through one intermediate vertex as the intermediate vertex might be updated).
// In the third pass, it checks paths that use 3 edges, and so on.
// Now, in a graph with n vertices, the longest path between any two points can have at most n-1 edges (because it can't have more than one edge from each vertex).

// So, after n-1 passes, you've considered all possible paths, even the longest ones. At this point, all the shortest paths are guaranteed to be correct.
// That's why we do n-1 passes — to account for every possible path, no matter how long!
*//Finding negative cycle using bellman algo
//if the graph(i.e distance) updates even after n-1 relaxation then there is a negative cycle present so we run one more time after n-1 
// relaxation to check if there is a negative cycle preset
*//code
 //  class graph {
	// public:
	// unordered_map<int, list<pair<int,int> > > adjList;

	// void addEdge(int u, int v, int wt, bool direction) {
	// 	//direction = 1 -> undirected graph
	// 	//direction => 0 -> directed graph;
	// 	adjList[u].push_back({v,wt});
	// 	if(direction == 1) {
	// 		adjList[v].push_back({u,wt});
	// 	}
	// }

	// void printAdjList() {
	// 	for(auto i: adjList) {
	// 		cout << i.first <<"-> ";
	// 		for(auto j: i.second) {
	// 			cout << "(" << j.first<<", "<<j.second<<"), ";
	// 		}
	// 		cout << endl;
	// 	}
	// }
void bellmanFordAlgo(int n, int src) {
		//assuming directed weightted graph
		vector<int> dist(n, INT_MAX);
		dist[src] = 0;
		//n-1 relaxation step
		for(int i=0; i<n-1; i++) {
			//for all edges
			for(auto t: adjList) {//they can be in any order
				for(auto nbr: t.second) {
					int u = t.first;
					int v = nbr.first;
					int wt = nbr.second;
					if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
						dist[v] = dist[u] + wt;
					}
				}
			}
		} 

		//to check for -ve cycle
		bool negativeCycle = false;
		for(auto t: adjList) {
				for(auto nbr: t.second) {
					int u = t.first;
					int v = nbr.first;
					int wt = nbr.second;
					if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {//if there are updates in distance even after n-1 then there is -ve cycle present
						negativeCycle = true;
						break;
					}
				}
			}

		if(negativeCycle == true) 
			cout << "-ve cycle present";
		else
			cout << "-ve cycle absent";

		cout << "printing dist array: ";
		for(auto i : dist)
			cout << i << " ";
		
	}
};

