https://leetcode.com/problems/n-queens/description/
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4//placing 4 queens such that no 2 queens can attack each other
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9
class Solution {
public:
    void storeSolution(vector<vector<char>>& board,vector<vector<string>>&ans,int n){ 
        vector<string> temp;
        for(int i=0;i<n;i++){
             string output="";
            for(int j=0;j<n;j++){
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }
    bool isSafe(int row,int col,vector<vector<char>>&board,int n){//time Complexity:O(n) 
        int i=row;
        int j=col;
        //checking row
        while(j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            j--;
        }
        //checking upward diagonal
        i=row;
        j=col;
        while(j>=0&&i>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        //checking downward diagonal
        i=row;
        j=col;
        while(j>=0&&i<n){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<char>>&board,vector<vector<string>>&ans,int col,int n){
        if(col>=n){
            storeSolution(board,ans,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(board,ans,col+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
           vector<vector<string>> ans;
           int col=0;
        solve(board,ans,col,n);
        return ans;
    }
};
*//************************************************************************************************************************
as the time complexity of isSafe function in O(n) to reduce it to O(1) we are using unordered map as its time complexity isO(1)
to check row
rowCheck[row]==true then queen is present in row
to check upperLeftDiagonal
upperLeftDiagonal[n-1+col-row]==true;//if it comes true then it has q in upper diagonal
to check bottomLeftDiagonal
bottomLeftDiagonal[row+col]==true;//eg:bottomLeftDiagonal of 3,0 will be 1,2 , 2,1 , 3,0 if we map them using row+col  we can find all the bottom left diagonal
      0       1       2       3
0     -   |   -   |   -   |   -
1     -   |   -   |   -   |   -
2     -   |   -   |   -   |   -
3     -   |   -   |   -   |   -
class Solution {
public:
unordered_map<int,bool> rowCheck;
unordered_map<int,bool>upperLeftDiagonal;
unordered_map<int,bool>bottomLeftDiagonal;
    void storeSolution(vector<vector<char>>& board,vector<vector<string>>&ans,int n){ 
        vector<string> temp;
        for(int i=0;i<n;i++){
             string output="";
            for(int j=0;j<n;j++){
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }
    bool isSafe(int row,int col,vector<vector<char>>&board,int n){
        if(rowCheck[row]==true){
            return false;
        }
        if(upperLeftDiagonal[n-1+col-row]==true){
            return false;
        }
        if(bottomLeftDiagonal[row+col]==true){
            return false;
        }
        return true;
        // int i=row;
        // int j=col;
        // //checking row
        // while(j>=0){
        //     if(board[i][j]=='Q'){
        //         return false;
        //     }
        //     j--;
        // }
        // //checking upward diagonal
        // i=row;
        // j=col;
        // while(j>=0&&i>=0){
        //     if(board[i][j]=='Q'){
        //         return false;
        //     }
        //     i--;
        //     j--;
        // }
        // //checking downward diagonal
        // i=row;
        // j=col;
        // while(j>=0&&i<n){
        //     if(board[i][j]=='Q'){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }
        // return true;
    }
    void solve(vector<vector<char>>&board,vector<vector<string>>&ans,int col,int n){
        if(col>=n){
            storeSolution(board,ans,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                rowCheck[row]=true;
                upperLeftDiagonal[n-1+col-row]=true;
                bottomLeftDiagonal[row+col]=true;
                solve(board,ans,col+1,n);
                //backtracing
                board[row][col]='.';
                rowCheck[row]=false;
                upperLeftDiagonal[n-1+col-row]=false;
                bottomLeftDiagonal[row+col]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
           vector<vector<string>> ans;
           int col=0;
        solve(board,ans,col,n);
        return ans;
    }
};
Time Complexity:O(N^N)
Space Complexity:The space complexity is O(n^2) because output matrix is required, so an extra space of size n*n is needed.
