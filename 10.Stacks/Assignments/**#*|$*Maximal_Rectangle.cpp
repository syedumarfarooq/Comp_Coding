https://leetcode.com/problems/maximal-rectangle/description/
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
*//*******
class Solution {
    vector<int> nextSmallest(vector<int> v){
  stack<int> s;
  s.push(-1);
  vector<int> ans(v.size());
  for(int i=v.size()-1;i>=0;i--){
      int curr=v[i];
      while(s.top()!=-1&&v[s.top()]>=curr){
        s.pop();
      }
      ans[i]=s.top();
      s.push(i);
  }
  return ans;
}
// Finding the prev smallest element
vector<int> prevSmallest(vector<int> v){
  stack<int> s;
  s.push(-1);
  vector<int> ans(v.size());
  for(int i=0;i<v.size();i++){
      int curr=v[i];
      while(s.top()!=-1&&v[s.top()]>=curr){
        s.pop();
      }
      ans[i]=s.top();
      s.push(i);
  }
  return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=INT_MIN;
        vector<int> prev=prevSmallest(heights);
        vector<int> next=nextSmallest(heights);
        int size=heights.size();
        for(int i=0;i<heights.size();i++){
            int length=heights[i];
            if(next[i]==-1){//as -1 comes if the there is no next smallest so if there is no next smallest we will point to the end of the array so find the width 
                next[i]=size;
            }
            int width=next[i]-prev[i]-1;
            int area=length*width;
            maxArea=max(area,maxArea);
        }
        return maxArea;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            vector<int> t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                v[i][j]+=v[i-1][j];
            }else{
                v[i][j]=0;
            }
        }
        area=max(area,largestRectangleArea(v[i]));
    }
    return area;
    }
};
