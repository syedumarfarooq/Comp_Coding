https://leetcode.com/problems/sudoku-solver/description/
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

 

// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:
// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.
class Solution {
public:
bool isSafe(char value,int curr_row,int curr_col,vector<vector<char>>& board){
    int n=board[0].size();
    for(int i=0;i<n;i++){
    //row check
        if(board[curr_row][i]==value){
            return false;
        }
    //column check
        if(board[i][curr_col]==value){
            return false;
        }
    //3*3 box check
        if(board[3*(curr_row/3)+(i/3)][3*(curr_col/3)+(i%3)]==value){
            return false;
        }
    }
    return true;
    
}
bool solve(vector<vector<char>>& board){
    int n=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //check for empty cell
            if(board[i][j]=='.'){
                //try to fill values from 1 to 9
                for(char value='1';value<='9';value++){
                    //check for safety
                    if(isSafe(value,i,j,board)){
                        board[i][j]=value;
                        //next solution is all true then no need to check for 
                        //other values of value as there is only one solution
                        //no need to find multiple solution
                        bool remainingBoardSolution=solve(board);
                        if(remainingBoardSolution==true){
                            return true;
                        }else{
                            board[i][j]='.';
                        }
                        
                    }
                }
                //if all the values of value are tried and none of it fits the 
                //cell return false
                //if 1-9 tak koi bhi value se solution
                //nahi nikla,current cell pr,
                //that means piche kahin pr galti hai,
                //go back by returning false;
                return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
Time Complexity:O(9^N)
Space Complexity:O(N*N)
};
