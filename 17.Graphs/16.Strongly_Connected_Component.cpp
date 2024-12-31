*//Strongly connected component
  *//Kosaraju algorithm
// A strongly connected component is a component(group of vertex) in which from any vertex u can reach any other vertex of that component
*//question can be asked only in two ways 1. is count the number of component or print the strongly connected component
*//logic
// if we are solving this using dfs in dfs it iterates the entire graph, by this we cannot find the number of strongly connected components
// eg;there is graph consisting 3 scc scc1->scc2->scc3 with this u cannot differentiate when one scc is finished and new one starts
// what if we reverse the edge of scc i.e scc1<-scc2<-scc3 we can apply dfs to every component and it will stop at end of every scc as there 
// is no connection to next scc and cannot go to previous as it is already visited
*//y reversing 
// we reverse because we can travrse every scc individually than traverse the whole graph
// Steps
// 1.find ordering in which we should traverse the graph this can be done using topological sort
// 2.reverse all edges as we cannot find the end of scc1 and begining of scc2 to reverse it so we are reversing all edges
// 3.count component using the ordering i.e u iterate the every node in the ordering eand mark visited using dfs if the dfs ends then we 
      // move the next node in the given ordering
*//code
// class graph {
//     public:
//     unordered_map<int, list<int> > adjList;

//     void addEdge(int u, int v, bool direction) {
//         //direction = 1 -> undirected graph
//         //direction => 0 -> directed graph;
//         adjList[u].push_back(v);
//         if(direction == 1) {
//             adjList[v].push_back(u);
//         }
//     }
  void dfs1topo(int src, stack<int>& s, unordered_map<int,bool>& vis) {//finding the topological sort i.e ordering
        vis[src] = true;

        for(auto nbr: adjList[src]) {
            if(!vis[nbr]) {
                dfs1(nbr, s, vis);
            }
        }
        s.push(src);
    }

    void dfs2(int src, unordered_map<int,bool>& visited, unordered_map<int,list<int> >& adjNew) {//dfs parsing for traversing all elements
        visited[src] = true;
        cout << src << ", ";

        for(auto nbr: adjNew[src]) {
            if(!visited[nbr] ) {
                dfs2(nbr, visited, adjNew);
            }
        }
    }
    
    int countSCC(int n) {
        stack<int> s;
        unordered_map<int,bool> visited;

        //find topo ordering
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs1topo(i,s,visited);
            }
        }

        //reverse all edges
        unordered_map<int,list<int> > adjNew;//storing it in new adj list
        
        for(auto t: adjList) {
            for(auto nbr: t.second) {
                int u = t.first;
                int v = nbr;
                //v-> u insert
                adjNew[v].push_back(u);
            }
        }

        //traversse using DFS to find all the scc
        int count = 0;
        unordered_map<int,bool> visited2;//visited for traversing using dfs

        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!visited2[node]) {
                cout << "Printing "<< count+1 << "th SCC: ";
                dfs2(node,visited2, adjNew);
                cout << endl;
                count++;
            }

            
        }

        

        return count;
    }
};
// int main(){
  // g.addEdge(0,1,0);
    
    // g.addEdge(1,2,0);
    
    // g.addEdge(2,3,0);
    
    // g.addEdge(3,0,0);
    
    // g.addEdge(2,4,0);
    
    // g.addEdge(4,5,0);
    
    // g.addEdge(5,6,0);
    
    // g.addEdge(6,4,0);
    
    // g.addEdge(6,7,0);

    // int ans = g.countSCC(8);
    // cout << "Number of SCC: " << ans << endl;
      // return 0;
// }
