https://leetcode.com/problems/minimum-number-of-refueling-stops/
// A car travels from a starting position to a destination which is target miles east of the starting position.

// There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.

// The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

// Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.

// Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

 

// Example 1:

// Input: target = 1, startFuel = 1, stations = []
// Output: 0
// Explanation: We can reach the target without refueling.
// Example 2:

// Input: target = 100, startFuel = 1, stations = [[10,100]]
// Output: -1
// Explanation: We can not reach the target (or even the first gas station).
*//LOGIC***
// we starting to move with the starting fuel toward destination ans store the fuel station which lie in between somewhere then to increase the 
// chance of reaching the destination using greedy method will go the fuel station which has maximum amount of fuel i.e we are not refulling 
// at the gas station which is near to when refueling needs to be done we will refuel it at the gas station which has the maximum fuel to offer
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {       
        int stops=0;
        int fuel=startFuel;
        int dist=0;
        int i=0;
        priority_queue<pair<int,int>>pq;//fuel,position
        while(true){
            while(i<stations.size()){
                //push all station within reach with my currenct fuel levels from my current position
                if(stations[i][0]<=dist+fuel){
                    pq.push({stations[i][1],stations[i][0]});
                }else{
                    break;
                }
                i++;
            }
            //travel with full fuel level to check if we have reached destination
            dist+=fuel;
            fuel=0;
            //reached target
         //checking at top because what if the startfuel is enough to reach target
            if(dist>=target)break;
            //no fuel station within reach with current fuel 
            if(pq.empty()){
                stops=-1;
                return stops;
            }
            //refuel and re-adjust fuel and distance  based on the distance travelled  till that station as we are refuelling at the gas station which has maximum fuel to offer
            auto&top=pq.top();
            fuel=(dist-top.second)+top.first;
            dist=top.second;
            pq.pop();
            ++stops;
        }
        return stops;
    }
};
