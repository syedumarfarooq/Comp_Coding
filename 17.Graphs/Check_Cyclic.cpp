// Check if there is a cycle present in the graph
// if a next node is already visited and and the current node is not the parent of next node then there is a cycle present
//if a node is already visited then it might have visited through the parent and if u visit that node and again and parent is different 
// then there is cycle present
#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class Graph {
public:
	unordered_map<T, list<T > > adjList;

	void addEdge(T u, T v, bool direction) {
		//direction = 0 -> undirected graph
		//direction = 1 -> directed graph
		//create an edge from u to v
		adjList[u].push_back(v);
		if(direction == 0)
		{
			//undirected edge
			//create an edge from v to u
			adjList[v].push_back(u);
		}
	}

	void printAdjacencyList() {
		for(auto node: adjList) {
			cout << node.first << "-> " ;
			for(auto neighbour: node.second) {
				cout <<neighbour<<", ";
			}
			cout << endl;
		}
	}

	void bfs(int src, unordered_map<int, bool>& visited) {
		queue<int> q;
		
		q.push(src);
		visited[src] = true;

		while(!q.empty()) {
			int frontNode= q.front();
			q.pop();
			cout << frontNode << ", ";

			//insert neighbours
			for(auto neighbour: adjList[frontNode]) {
				if(!visited[neighbour] ) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void dfs(int src, unordered_map<int, bool>& visited) {
		cout << src << ", ";
		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour] ) {
				dfs(neighbour, visited);
			}
		}
	}
*//check cyclic in BFS
bool checkCyclicUsingBfs(int src, unordered_map<int,bool>& visited) {
		queue<int> q;
		unordered_map<int,int> parent;
		
		q.push(src);
		visited[src] = true;
		parent[src] = -1;

		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();

			for(auto nbr: adjList[frontNode]) {
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr]=frontNode;
				}
				if(visited[nbr] && nbr!= parent[frontNode]) {//if neighbour is revisited and the neighbour is not  current node parent 
          //as the neighbour can be the parent of frontNode if yes then no cycle if not cycle
						//cycle present
						return true;
				}
			}
		}
		return false;
	}
*//check cyclic in DFS
bool checkCyclicUsingDfs(int src, unordered_map<int,bool>& visited, int parent) {
		visited[src] = true;

		for(auto nbr: adjList[src]) {
			if(!visited[nbr]) {
				bool checkAageKaAns = checkCyclicUsingDfs(nbr, visited, src);
				if(checkAageKaAns == true)//if there is cycle present return true
					return true;
			}
			if(visited[nbr] && nbr != parent) {
				//cycle present
				return true;
			}
		}
		return false;
	}

*//chech cyclic for directed graph using dfs // bfs will be taught in later duration as it needs some prerequisites
//in this we are making visited and dfs_visited if node is visited and dfs is called for that node if the node and dfs_visited are true
// we consider it as cyclic and if we have to make dfs_visited false if we are backtracking after reaching the last node as if 
//dfs_visited can be accessed by some other parent 
bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int,bool>& visited,
unordered_map<int,bool> dfsVisited) {

		visited[src] = true;
		dfsVisited[src] = true;//keeping track of recursive call if dfs of any node is called we mark true

		for(auto nbr: adjList[src]) {
			if(!visited[nbr]) {
				bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
				if(aageKaAnswer == true)
					return true;
			}
			if(visited[nbr] == true && dfsVisited[nbr] == true) {
				return true;
			}
		}
		//yaha hi galti hoti h 
		*//IMP
		dfsVisited[src] = false;//while comming back we remove the entry of the dfs call bcz even if it is not cyclic and it may call same dfs
//if it comes true then we say cyclic
// eg;1-2,2-3,2-4,3-4, we call dfs for 1,2,3,4 mark true and return if we dont make them false while returning we call dfs 4 again from 2
// this may think it is cyclic from our logic but it is not so while comig back if we mark false then for 2-4 then it will mark true again
// eg;1-2-3-4 we call dfs for 1,2,3,4,1 but for the second time 1 appers it is already visited and dfs visited then only we consider it as
// cycle
// i.e if it is(node) present in the same Call stack(dfs 1,2,3 is a call stack) we say its cyclic if it is in different we dont
		return false;
	}
};
int main() {

	Graph<int> g;
	//n -> number of nodes in graph
	int n = 5;
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(3,4,1);
	g.addEdge(4,0,1);

	g.printAdjacencyList();
	cout << endl;

	// bool ans = false;
	// unordered_map<int, bool> visited;
	// for(int i=0; i<n; i++) {
	// 	if(!visited[i]) {
	// 		 ans = g.checkCyclicUsingBfs(i,visited);
	// 		if(ans == true)
	// 			break;
	// 	}
	// }
  // bool ansDfs = false;
	// unordered_map<int, bool> visitedDfs;
	// for(int i=0; i<n; i++) {
	// 	if(!visitedDfs[i]) {
	// 		 ansDfs = g.checkCyclicUsingDfs(i,visitedDfs, -1);
	// 		if(ansDfs == true)
	// 			break;
	// 	}
	// }
  bool ans = false;
	unordered_map<int, bool> visited;
	unordered_map<int, bool> dfsVisited;
	for(int i=0; i<n; i++) {
		if(!visited[i] ) {
			ans = g.checkCyclicDirectedGraphUsingDfs(i,visited,dfsVisited);
			if(ans == true)
				break;
		}
	}
	if(ans == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;
}
