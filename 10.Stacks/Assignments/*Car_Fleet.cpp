https://leetcode.com/problems/car-fleet/description/
// There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

// You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

// A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

// A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

// If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

// Return the number of car fleets that will arrive at the destination.

 

// Example 1:

// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

// Output: 3

// Explanation:

// The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
// The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
// The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
class Solution {
    class Car{
        public:
        int pos,speed;
        Car(int p,int s):pos(p),speed(s){};
    };
    static bool myCom(Car &a,Car &b){
        return a.pos<b.pos;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for(int i=0;i<position.size();i++){
            Car car(position[i],speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(),cars.end(),myCom);
        stack<float> st;
        for(auto car:cars){
            float time=(target-car.pos)/((float)car.speed);
            while(!st.empty() &&time>=st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};
