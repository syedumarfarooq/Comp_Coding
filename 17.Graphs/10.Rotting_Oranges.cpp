https://leetcode.com/problems/rotting-oranges/
// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
// Example 1:
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
*//logic
//   In this we have to solve using bfs bcz for every level of fresh oranges we add one minute we do this until every level and every orange 
// is iterated 

*//code
  class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int> , int > > q;//<coordinates,time>
        vector<vector<int>> arr = grid;
        int count = 0;
        int ansTime = 0;
        //insert all rotten oranges in queue
        for(int row=0; row<grid.size(); row++) {
            for(int col=0; col<grid[row].size(); col++ ) {
                if(grid[row][col] ==2) {
                    //rotten orange found push into queue
                    pair<int,int> coordinate = make_pair(row, col);
                    q.push({coordinate,0});
                }
            }
        }

        while(!q.empty()) {
            pair<pair<int,int> , int > fNode = q.front();
            q.pop();
            int x = fNode.first.first;
            int y = fNode.first.second;
            int time = fNode.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >=0 && newX < arr.size() && newY >=0 && newY < arr[0].size() &&
                 arr[newX][newY] == 1) {
                     pair<int,int> newCoordinates = make_pair(newX, newY);
                     ansTime = max(ansTime, time+1);//we are keeping track of maximum time so that we return maxtime that is taken to rot orange
                  //for every level time increases as we keep a track of time bcz we want maximum time after the q is empty i.e 
                  // max time taken to rot all oranges in the queue
                     q.push({newCoordinates, time + 1});
                     //mark rotten
                     arr[newX][newY] = 2;
                 }
            }


        }

        //check  for fresh orange i.e if there are any other fresh oranges left after rotting the enrire grid then we have to return -1 
      // as we could not rot all oranges
      *//we can replace this by keeping count of all fresh oranges while checking for rotten and count-- when we make it rotten 
      // in the end if we compare the original and the rottern if the result >0 i.e there are still fresh oranges left we return -1
        for(int i=0;i<arr.size(); i++) {
            for(int j=0;j<arr[0].size();j++) {
                if(arr[i][j] == 1) {
                    return -1;
                }
            }
        }
       return ansTime;

    }
};
