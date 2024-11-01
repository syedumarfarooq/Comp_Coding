https://leetcode.com/problems/k-closest-points-to-origin/description/
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

// Example 1:


// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
class Solution {
public:
    class compare{
        public:
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            int distA=a.first*a.first+a.second*a.second;//the distance between two points is √(x1 - x2)2 + (y1 - y2)2).
          // as we are calculating the distance from the origin the x2 and y2 component becomes 0 as the origin points are 0,0 
          //so the distance will be √x1*x1+y1*y1 as we need not calculate sqrt we only use x1*x1+y1*y1 to compare the distance 
          //of all thorugh this we can find the minimum distance from the origin using min heap
            int distB=b.first*b.first+b.second*b.second;
            return distA>distB;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(auto p:points){
            pq.push({p[0],p[1]});
        }
        while(!pq.empty()&&k--){
            auto&top=pq.top();
            ans.push_back({top.first,top.second});
            pq.pop();
        }
        return ans;
    }
};
