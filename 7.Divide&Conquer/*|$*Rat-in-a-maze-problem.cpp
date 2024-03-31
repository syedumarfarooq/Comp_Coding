https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.
//{ Driver Code Starts
// Initial template for C++



class Solution{
    public:
    bool isSafe(int i,int j,int row,int col,vector<vector<int>>& m,vector<vector<bool>>& visited){
        if((i>=0&&i<row)&&(j>=0&&j<col)&&(visited[i][j]==false)&&(m[i][j]==1)){
            return true;
        }else{
            return false;
        }
    }
    void solveMaze(vector<vector<int>>& m,int row,int col,int i,int j,vector<vector<bool>>& visited,
    vector<string>& path,string output) {
        if(i==row-1&&j==col-1){
            path.push_back(output);
                return;
            
        }
        //down
        if(isSafe(i+1,j,row,col,m,visited)){
            visited[i+1][j]=true;
            solveMaze(m,row,col,i+1,j,visited,path,output+'D');
            //backtracking to find other possible solution
             visited[i+1][j]=false;
        }
        //left
        if(isSafe(i,j-1,row,col,m,visited)){
            visited[i][j-1]=true;
            solveMaze(m,row,col,i,j-1,visited,path,output+'L');
            //backtracking to find other possible solution
             visited[i][j-1]=false;
        }
        //right
        if(isSafe(i,j+1,row,col,m,visited)){
            visited[i][j+1]=true;
            solveMaze(m,row,col,i,j+1,visited,path,output+'R');
            //backtracking to find other possible solution
             visited[i][j+1]=false;
        }
        //up
        if(isSafe(i-1,j,row,col,m,visited)){
            visited[i-1][j]=true;
            solveMaze(m,row,col,i-1,j,visited,path,output+'U');
            //backtracking to find other possible solution
             visited[i-1][j]=false;
        }
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int row=n;
        int col=n;
        vector<string> path;
        string output="";
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        
        if(m[0][0]==0){//if the starting position cannot be visited then it cannot reach the destination
        //so it will return empty path
            return path;
        }
        visited[0][0]=true;//marking the value of the source as visited
        solveMaze(m,row,col,0,0,visited,path,output);
        return path;
    }
};
*//***************************************************************************************************************************************



class Solution{
    public:
    int dx[4]={1,0,0,-1};
    int dy[4]={0,-1,1,0};
    char direction[4]={'D','L','R','U'};
    bool isSafe(int i,int j,int row,int col,vector<vector<int>>& m,vector<vector<bool>>& visited){
        if((i>=0&&i<row)&&(j>=0&&j<col)&&(visited[i][j]==false)&&(m[i][j]==1)){
            return true;
        }else{
            return false;
        }
    }
    void solveMaze(vector<vector<int>>& m,int row,int col,int i,int j,vector<vector<bool>>& visited,
    vector<string>& path,string output) {
        if(i==row-1&&j==col-1){
            path.push_back(output);
                return;
            
        }
        
        // //down
        // if(isSafe(i+1,j,row,col,m,visited)){
        //     visited[i+1][j]=true;
        //     solveMaze(m,row,col,i+1,j,visited,path,output+'D');
        //     //backtracking to find other possible solution
        //      visited[i+1][j]=false;
        // }
        // //left
        // if(isSafe(i,j-1,row,col,m,visited)){
        //     visited[i][j-1]=true;
        //     solveMaze(m,row,col,i,j-1,visited,path,output+'L');
        //     //backtracking to find other possible solution
        //      visited[i][j-1]=false;
        // }
        // //right
        // if(isSafe(i,j+1,row,col,m,visited)){
        //     visited[i][j+1]=true;
        //     solveMaze(m,row,col,i,j+1,visited,path,output+'R');
        //     //backtracking to find other possible solution
        //      visited[i][j+1]=false;
        // }
        // //up
        // if(isSafe(i-1,j,row,col,m,visited)){
        //     visited[i-1][j]=true;
        //     solveMaze(m,row,col,i-1,j,visited,path,output+'U');
        //     //backtracking to find other possible solution
        //      visited[i-1][j]=false;
        // }
        //the above code can be minimized into shorted code
        for(int k=0;k<4;k++){
            int newx=i+dx[k];
            int newy=j+dy[k];
            char dir=direction[k];
            if(isSafe(newx,newy,row,col,m,visited)){
                visited[newx][newy]=true;
            solveMaze(m,row,col,newx,newy,visited,path,output+dir);
            //backtracking to find other possible solution
             visited[newx][newy]=false;
            }
        }
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int row=n;
        int col=n;
        vector<string> path;
        string output="";
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        
        if(m[0][0]==0){//if the starting position cannot be visited then it cannot reach the destination
        //so it will return empty path
            return path;
        }
        visited[0][0]=true;//marking the value of the source as visited
        solveMaze(m,row,col,0,0,visited,path,output);
        return path;
    }
};
Time Complexiy:O(4^n)
    



