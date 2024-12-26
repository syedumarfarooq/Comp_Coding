https://leetcode.com/problems/number-of-islands/
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// *//logic
// we are first iterating from 0,0 and pushing into the queue we are taking the front and traversing all 4 direation if it is 1 we mark visited
// until the queue is empty after that we iteratie through every element in the grid and check if there are any islands left that is any '1'
// left if yes pass that value into bfs to check its all neighbours 
// and every time the q becomes empty that means one island is covered i.e all the neighbouring '1' are iterated rest all is 0 surrounding it
*//code
class Solution {
private:
    void bfs(map<pair<int,int>,bool>&visited,int row,int col,vector<vector<char>>& grid){
        queue<pair<int,int>> q;//<coordinates>
        q.push({row,col});
        visited[{row,col}]=true;
        while(!q.empty()){
            pair<int,int> fNode=q.front();
            q.pop();
            int x=fNode.first;
            int y=fNode.second;

            //i can move in 4 directions 
            int dx[]={-1,0,1,0};//URDL
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[row].size() && !visited[{newX,newY}] &&
                grid[newX][newY]=='1'){
                    q.push({newX,newY});
                    visited[{newX,newY}]=true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,bool>  visited;
        int count=0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(!visited[{row,col}]&&grid[row][col]=='1'){//we any island we not visited we pass that value into bfs for covering all its
                  //neighbours and marking them visited
                    bfs(visited,row,col,grid);
                    count++;//count after q becomes empty as ther are no neigbouring 1 left in the grid
                }
            }
        }
        return count;
    }
};
