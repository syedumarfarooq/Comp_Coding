https://leetcode.com/problems/car-fleet-ii/description/
// There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n, where cars[i] = [positioni, speedi] represents:

// positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that positioni < positioni+1.
// speedi is the initial speed of the ith car in meters per second.
// For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.

// Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.

 

// Example 1:

// Input: cars = [[1,2],[2,1],[4,3],[7,2]]
// Output: [1.00000,-1.00000,3.00000,-1.00000]
// Explanation: After exactly one second, the first car will collide with the second car, and form a car fleet with speed 1 m/s. After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans(cars.size(),-1);
        stack<int>st;
        for(int i=cars.size()-1;i>=0;i--){
            //check if car ahead of current car is faster is so they wont collide
            while(!st.empty()&& cars[st.top()][1]>=cars[i][1]){
                st.pop();
            }
            while(!st.empty()){
                double colTime=(double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(ans[st.top()]==-1||colTime<=ans[st.top()]){//if colition time of present car is less than the next car then only it will
                  // save or else untill it will collide with the next car, the next car will have collided with the car in front and they 
                  // become a single entity so we have to measure the collition time the next's next car
                  
                    ans[i]=colTime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }   
};
