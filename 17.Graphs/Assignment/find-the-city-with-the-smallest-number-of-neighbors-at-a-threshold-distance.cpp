https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
*//logic
  // we are using dijkstra algo to find the smallest distance of each city to every other city using this we find the number of cities which
// have distance less than the distanceThreshold 
//so for every src node we have the no. of cities it can reach with the given threshold 
//using that we will find the minimum and return if they are same then we return the greatest city in terms of its value
*//code
  class Solution {
public:
    int shortestDistDijkstra(int src, int n,unordered_map<int,list<pair<int,int>>>&adjList,int &distanceThreshold) {
		vector<int> dist(n,INT_MAX);
		set<pair<int,int> > st;//distance,node
		//intiial steps
		dist[src] = 0;
		st.insert(make_pair(0,src));
        int rechableCities=0;//cities have atmost distanceThreshold distance
		while(!st.empty() ) {
			auto topElement = *(st.begin());
            st.erase(st.begin());
			int nodeDistance = topElement.first;
			int node = topElement.second;
      //in dijkstra when we enter a node that node will have the shortest path then only we can continue by adding that distance to its neighbour
      //and find its shortes 
      //u may have a doubt we could calculate at the end why begining so the node will have the shortest path 
            if(node!=src && nodeDistance<=distanceThreshold){//calculating the cities which have at most distanceThreshold distance
                rechableCities++;
            }

		    //neighbour traverse
			for(auto nbr: adjList[node]) {
				if(nodeDistance + nbr.second < dist[nbr.first]) {
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

		return rechableCities;
		
	}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>> adjList;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        int city=0;
        int minReachableCities=INT_MAX;
        for(int u=0;u<n;u++){
            int reachableCitiesCount=shortestDistDijkstra(u,n,adjList,distanceThreshold);
            if(reachableCitiesCount<=minReachableCities){//this will give us the city which has the minimum count of reachable citites
              // <= at one point we might get reachableCitiesCount same for many cities if we use = sign we can return the greates value of u
                minReachableCities=reachableCitiesCount;
                city=u;
            }
        }
        return city;
    }
};
