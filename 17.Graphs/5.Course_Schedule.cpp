https://leetcode.com/problems/course-schedule/
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
*//logic
  // as the question says prerequisites[i] = [ai, bi] we should comple bi to do ai so ai is dependent on bi so by this we are infering 
// topological sort as it is based on dependency
  // as  ai is dependent on bi we can create a graph bi->ai and find topological sort if the graph has any cycles then we cannot complete the 
// courses eg;1-2-3-1 to complete 3 we want 2 to compelete 2 we want 1 to complete 1 we want 3 so this cannot be possible
// if the ans we get is equal to number of nodes then we say we have no cycles and the courses can be completed or else we cannot
  *//code
  class Solution {
private:
    bool topoSortBfs(int n,unordered_map<int,list<int>>&adjList) {
		queue<int> q;
        vector<int> ans;
		unordered_map<int, int> indegree;
        //indegree calculate
		for(auto i: adjList ) {
			int src = i.first;
			for(auto nbr:i.second) {
				indegree[nbr]++;
			}
		}

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
			for(auto nbr: adjList[fNode]) {
				indegree[nbr]--;
				//check for zero again
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}	
			}
			
		}
		if(ans.size()==n){
            return true;
        }else{
            return false;
        }
	}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adjLists;
        for(auto task:prerequisites){
            int u=task[0];
            int v=task[1];
            adjLists[v].push_back(u);
        }
        bool ans=topoSortBfs(numCourses,adjLists);
        return ans;
    }
};
