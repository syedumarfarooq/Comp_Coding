https://leetcode.com/problems/flood-fill/
*//u may find it very easy but mistake prone so practise properly
// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill:
// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.
// Example 1:
// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

// Output: [[2,2,2],[2,2,0],[2,0,1]]
*//logic
 // in this using the src node we are traversing all its neighbours if they are of same color we change its color and iterate further using dfs

*//code
class Solution {
    private:
    void dfs(int x, int y, int oldColor, int newColor, map<pair<int,int>, bool>& vis,vector<vector<int> >& arr ) {

        vis[{x,y}] = true;
        arr[x][y] = newColor;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0; i<4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX>=0 && newX<arr.size() && newY>=0 && newY<arr[0].size()&&
                !vis[{newX, newY}]  && arr[newX][newY]==oldColor) {
                    dfs(newX, newY, oldColor, newColor, vis, arr);   
                }
        }
    }
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldColor = image[sr][sc];
        map<pair<int,int>, bool> vis;
        vector<vector<int>> ans = image;
        dfs(sr,sc,oldColor,color,vis,ans);
        return ans;
    }
};
