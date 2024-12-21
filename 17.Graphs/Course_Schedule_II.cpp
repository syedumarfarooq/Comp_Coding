https://leetcode.com/problems/course-schedule-ii/
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
*//logic
  // same as course schedule but in that we are returning true or false in this we are returning the topological sort array i.e ans array if 
  // it is valid i.e not cyclic and empty array if cyclic
  //if there is cycle present we can complete the course as the every course is dependent on one another so we cannot start anywhere
*//code
  class Solution {
private:
    vector<int> topoSortBfs(int n,unordered_map<int,list<int>>&adjList) {
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
            return ans;
        }else{
            return {};
        }
	}
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adjLists;
        for(auto task:prerequisites){
            int u=task[0];
            int v=task[1];
            adjLists[v].push_back(u);
        }
        vector<int> ans=topoSortBfs(numCourses,adjLists);
        return ans;
    }
};
