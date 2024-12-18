*//Graphs
// Graph is a type of data structure made up of nodes and edges
//nodes stores data and edges connects nodes
*//Types of Graphs
//1.directed graph 
  // graph whose edges are directed
//2.undirected graph
  //graph whose edges are undirected i.e thier edges are bidirectional
//3.weighted directed and undirected graphs
*//Degree
//1.Undirected graph
// in undirected graph the number of edges from a node is a number of degree
// 2.Directed graph
// there are two types 
// -Indegree
      // in this we only count the number of edges which are directed toward the node
// Outdegree 
      // in this we only count the number of edges which are directed away from the node
*//path
   // sequence of number which are traversed but make sure u traverse every node once
*//Cyclic graph
  //A cyclic graph is a directed graph that contains a path from at least one node back to itself if weights are added it is called weighted directed cyclic graph
*//Acyclic graph
  //a graph that has no cycles
*//Graph Implementation
  // graph can be implemented in 2 ways
  // 1.Adjacency Matrix (2D Array)
  // 2.Adjacency List   (map,vector,list,set)
#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class Graph {
public:
  unordered_map<T, list<T > > adjList;//unordered_map<int, list<pair<int,int> > > adjList;//pair<destination node,weight>// if u want to add weight use pair

  void addEdge(T u, T v, bool direction) {//Template It’s a way to create generic code that works for different data types without having to rewrite the same code multiple times.
// T is a placeholder for a type (like int, float, string, etc.) that gets decided when the template is used.
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
        cout <<neighbour<<", ";// cout <<"("<<neighbour.first<<","<<neighbour.second<<"), "; //if weigth was used i.e pair
      }
      cout << endl;
    }
  }
}
int main() {

  Graph<int> g;//Template T 
  //Graph<char> g;//we can use char in our char g.addEdge('a','b',0);
  //n -> number of nodes in graph
  //Undirected graph
  int n = 5;
  g.addEdge(0,1,0);
  g.addEdge(1,3,0);
  g.addEdge(0,2,0);
  g.addEdge(2,4,0);

  g.printAdjacencyList();
}
*//
