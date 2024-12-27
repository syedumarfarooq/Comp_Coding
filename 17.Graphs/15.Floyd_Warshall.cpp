*//Floyd Warshall
//in dijkstra's and bellman ford we finding sssp(single source shortest path)
// in Floyd Warshall we find mssp(multiple source shortest path)
// //in this we are finding the shortest distance from one to another by taking a helping node 
// eg: there are four nodes in this,so we have to find from all the nodes minimum distance for all the nodes
//   lets take one case finding distance from 1-4 it will first check 1-2-4 1-3-4 among this it will choose the shortest and it
// will do the same for the rest of the nodes so it will check all the permutations with the helper node in between
*//code
// class graph {
// 	public:
// 	unordered_map<int, list<pair<int,int> > > adjList;

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
  void floydWarshal(int n) {
  		vector<vector<int> > dist(n , vector<int>(n,1e9));//using 10^9 bcz if we use int_max in some case we migh add int_max with something 
  *//if we add something into INT_MAX it turns into negative as it wrapps around and goes to INT_MIN in our case we were getting negative
  // number and as it max minimum we were getting values in negative and near to INT_MIN
  		//diagnol pr zero mark krdo as the distance from one node to itself is 0
  		for(int i=0; i<n; i++) {
  			dist[i][i] = 0;
  		}
  		//graph k according dist insert krdia h this is not shortest path it is just the distance given in graph and updation starts in next loop
  		for(auto t: adjList) {
  			for(auto nbr: t.second) {
  				int u = t.first;
  				int v = nbr.first;
  				int wt = nbr.second;
  				dist[u][v] = wt;
  			}
  		}
  
  		for(int helper=0; helper<n; helper++) {
  			for(int src =0; src<n; src++) {
  				for(int dest=0; dest<n; dest++) {
  					dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
  				}
  			}
  		}
  
  		cout << "Printing distance array: " << endl;
  		for(int i=0; i<n; i++) {
  			for(int j=0; j<n; j++) {
  				cout << dist[i][j]<< ", ";
  			}
  			cout << endl;
  		}
  		
  	}
  };
//   int main() {
// 	graph g;

// 	g.addEdge(0,1,3,0);
// 	g.addEdge(0,3,5,0);
// 	g.addEdge(1,0,2,0);
// 	g.addEdge(1,3,4,0);
// 	g.addEdge(2,1,1,0);
// 	g.addEdge(3,2,2,0);
// 	/////////////////////

// 	g.printAdjList();
// 	g.floydWarshal(4);
// 	return 0;
// }
