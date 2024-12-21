*//Dijkstra_algorithm
//we can implement this using MIN_HEAP or SET(sorted and unique)
//using these two because we can find minimum element in O(1) time i.e constant time using these two data structures
//In this we are starting with the src marking the distance as 0 then take all its neighbours and update its distance and then remove the
//top element then find the next minimum distance element find its neighbour and update their distance and so on until all elements are 
//removed from the set 
//it is a greedy aproach minimum distance node's from that node we update the distance of its neighbour
// so basically we are finding the minimum distance to reach every node from the src
*//code
//   #include <iostream>
// #include<unordered_map>
// #include<list>
// #include<queue>
// #include<stack>
// #include<algorithm>
// #include<set>
// #include<limits.h>
// using namespace std;


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
*//shortest Path Using dijkstra
  void shortestDistDijkstra(int src, int n) {
		vector<int> dist(n,INT_MAX);
		set<pair<int,int> > st;//distance,node
		//intiial steps
		dist[src] = 0;
		st.insert(make_pair(0,src));

		while(!st.empty() ) {
			//fetch the smallest or first eklement from set
			auto topElement = *(st.begin());
			int nodeDistance = topElement.first;
			int node = topElement.second;

			//pop from set
			st.erase(st.begin());

				//neighbour traverse
			for(auto nbr: adjList[node]) {
				if(nodeDistance + nbr.second < dist[nbr.first]) {
					//mujhe distance update krna h 
					//as we cannot directly update value in set so we find remove and reinsert with different value
					//finding entry in set
					auto result = st.find(make_pair(dist[nbr.first], nbr.first));
					//if found, then remove
					if(result != st.end()) {
						st.erase(result);
					}
					//updation in dist array and set
					dist[nbr.first] = nodeDistance + nbr.second;
					st.insert(make_pair(dist[nbr.first], nbr.first));
				}
			}
			
		}

		cout << "printing ans:" << endl;
		for(int i=0; i<n; i++) {
			cout << dist[i] <<", ";
		}cout << endl;
		
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
// 	return 0;
// }
