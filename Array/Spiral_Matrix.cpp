// https://leetcode.com/problems/spiral-matrix/description/
// Given an m x n matrix, return all elements of the matrix in spiral order.
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int totalelements=m*n;
        int count=0;
        int startrow=0;
        int endingcolumn=n-1;
        int endingrow=m-1;
        int startcolumn=0;
        while(count<totalelements){
            for(int i=startcolumn;i<=endingcolumn&&count<totalelements;i++){
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            for(int i=startrow;i<=endingrow&&count<totalelements;i++){
                ans.push_back(matrix[i][endingcolumn]);
                count++;

            }
            endingcolumn--;
            for(int i=endingcolumn;i>=startcolumn&&count<totalelements;i--){
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;
            for(int i=endingrow;i>=startrow&&count<totalelements;i--){
                ans.push_back(matrix[i][startcolumn]);
                count++;
            }
            startcolumn++;
        }
        return ans;
    }
};
