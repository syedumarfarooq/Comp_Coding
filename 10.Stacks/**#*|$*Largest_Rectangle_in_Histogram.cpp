https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
class Solution {
public:
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
    
};
