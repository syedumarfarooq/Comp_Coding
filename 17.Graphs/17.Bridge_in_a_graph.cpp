*//Bridge in a graph using tarjan's algorithm
// Bridge is an edge in a graph on removing it will increase the count of number of disconnected component
// eg:a-b if we remove edge a-b then the number of disconnected component becomes 2 which is a and b
*//logic steps or conditions
// for every node we keep a track on insertion time and lowest insertion time
*//1.if parent lowest insertion time is greater than the child that means the child can be reached from other parent
// so if the parent can only reach the child i.e only one way  then the lowest insertion time of parent will be less than the child 
// the condition to form a bridge is when child can be visited only through parent, if the child can be visited from any other vertex
// then it is not a bridge
*//2.while updating lowest insertion time never consider parent node and add one
*//3.for a nodeA there is a possible path from other node other than parent (i.e nodeA child of some other node other than parent)
  // and already visited then nodeA lowest insertion time will be update based on the  node which is already visited as it will be lowest
*//4.lowest insertion time of child is less than the parent then there is a another way to reach child
*//5.while returning after accessing all nodes it will check if the child's lowest insertion time is less than the current nodes lowest 
  // insertion time if yes then it will update itself accordingly i.e it will update its lowest insertion time to the same as the childs
    // lowest insertion time
*//u may have doubt why not add +1 to lowest insertion time while updating the parent
//   bcz the lowest insetion time only indicates if there is a another way to reach the node so if the lowest insertion only places the role
// of telling the parent if the child can be reached through a different path 
// atlast irrespective of value if the value is less than the parent then there is a another way to access that node and it is not a bridge
// that is why we dont add 1
//  so we conclude the  lowest insetion time is not the shortest insertine time they are not same 
  *//logic
  // we are marking the source and time as 1 and 1 for source then we start iterating all its neihbour if the neighbour is parent we continue
  // if the neighbour is not visited then we apply dfs(i.e iterating all elements) while returing we update the lowest insertion time 
  // based on the children if the child's lowest insertion time is less than the parent then there is another way then the parent will surely
  // have another way from the children if there is children and that children has another path from another parent then the value will be updated
  // if so then we dont consider it as a bridge if the parent lowest insertion value is less then the childs then the child has no other parents
  // i.e it is a bridge
*//code
  // class graph {
  //   public:
  //   unordered_map<int, list<int> > adjList;

  //   void addEdge(int u, int v, bool direction) {
  //       //direction = 1 -> undirected graph
  //       //direction => 0 -> directed graph;
  //       adjList[u].push_back(v);
  //       if(direction == 1) {
  //           adjList[v].push_back(u);
  //       }
  //   }
    void findBridges(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int,bool> vis) {
    
            vis[src] = true;
            tin[src] = timer;
            low[src] = timer;
            timer++;
    
            for(auto nbr: adjList[src]) {
                if(nbr == parent)
                    continue;
                if(!vis[nbr]) {
                    //dfs call
                    findBridges(nbr, src, timer, tin, low, vis);
                    //low update
                    low[src] = min(low[src], low[nbr]);
                    //check for bridge
                    if(low[nbr] > low[src]) {
                        cout << nbr<<"--"<<src <<" is a bridge" << endl;
                    }
                }
                else{
                    //node is visited and not a parent
                    //low update
                    low[src] = min(low[src], low[nbr]);
                }
            }
            
            
        }
  };
// int main() {

//     graph g;

//     g.addEdge(0,1,1);
//     g.addEdge(1,2,1);
//     g.addEdge(2,0,1);
//     g.addEdge(1,6,1);
//     g.addEdge(3,1,1);
//     g.addEdge(1,4,1);
//     g.addEdge(3,5,1);
//     g.addEdge(4,5,1);

//     int n = 7;
//     int timer = 0;
//     vector<int> tin(n);
//     vector<int> low(n);
//     unordered_map<int,bool> vis;
//     g.findBridges(0, -1,timer, tin, low, vis);
//     return 0;
// }
