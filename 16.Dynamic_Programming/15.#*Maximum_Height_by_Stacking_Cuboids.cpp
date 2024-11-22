https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
// Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

// You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
// Return the maximum height of the stacked cuboids.
// Example 1:
// Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
// Output: 190
// Explanation:
// Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
// Cuboid 0 is placed next with the 45x20 side facing down with height 50.
// Cuboid 2 is placed next with the 23x12 side facing down with height 45.
// The total height is 95 + 50 + 45 = 190
*//logic 
  // using Longest increasing subsequence so we see if the current cuboid is less than the previous we include it in this we have return 
// highest height so we add up heigght
  //so first we sort all the length width height and make it in increasing order so that we can get maximum height as the question says
  //we can rotate the values and we want maximum height we rotate it in increasing order so last element is the greatest and that is
  //considered height
  class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {
        // curr should be greater than previous
        //as we have the arr in increasing order we are placing in opposite way we are placing the smallest then greater then greater
        //at last we have to return height wither way it will be same
        if(b[0] <= a[0] && b[1]<=a[1] && b[2] <= a[2])
            return true;
        else
            return false;
    }
    int solveUsingTabSO(vector<vector<int>>& arr) {
        int n = arr.size();
        //vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || check(arr[curr], arr[prev]))//changes here
                    include = arr[curr][2] + nextRow[curr + 1];
                    //we dont add it with 1 as we have to give height as output
                    //we are placing the previous on current so we include current height into the solution and move on next element
                //excude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);   
            }
            //shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
         //sort every array inside the 2d array
         //so that we can get the maximum element at the last so that we can consider it as height and get the maximum height as answer
        for(auto &a: cuboids) {
            sort(a.begin(), a.end());
        }
        
        //sort the 2D array
        //then we sort the 2d array based on the first element of every array so that we can compare the current with previous and add it and mostly keep in increasing order to apply LIS
        sort(cuboids.begin(), cuboids.end());

        //apply lis logic
        int ans = solveUsingTabSO(cuboids);
        return ans;
    }
};
