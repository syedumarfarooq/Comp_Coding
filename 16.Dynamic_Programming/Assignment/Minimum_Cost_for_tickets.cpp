// https://leetcode.com/problems/minimum-cost-for-tickets/
// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

 

// Example 1:

// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
// Output: 11
// Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
// On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
// On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
// On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
// In total, you spent $11 and covered all the days of your travel.
// Example 2:

// Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
// Output: 17
// Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
// On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
// On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
// In total, you spent $17 and covered all the days of your travel.
*//Using recursion
class Solution {
public:
int mincostTickets_helper(vector<int>& days,vector<int>& costs,int i){
    if(i>=days.size()){
        return 0;
    }
    //1 Day pass taken
    int cost1=costs[0]+mincostTickets_helper(days,costs,i+1);
    //7 Day pass taken
    int passEndDay=days[i]+7-1;//-1 because day[i] is included
    int j=i;
    while(j<days.size()&&days[j]<=passEndDay){
        j++;
    }
    int cost7=costs[1]+mincostTickets_helper(days,costs,j);
    //30 Day pass taken
    passEndDay=days[i]+30-1;//-1 because day[i] is included
     j=i;
    while(j<days.size()&&days[j]<=passEndDay){
        j++;
    }
    int cost30=costs[2]+mincostTickets_helper(days,costs,j);
    return min(cost1,min(cost7,cost30));
    
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincostTickets_helper(days,costs,0);
    }
};
Time Complexity:O(3^N)//}expaned in perfect square question
Space Complexity:O(N)//}expaned in perfect square question
 *//Solved using memoisation
  class Solution {
public:
    int mincostTicketsHelperMem(vector<int>& days,vector<int>& costs,int i,vector<int>& dp){
        if(i>=days.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int cost1=costs[0]+mincostTicketsHelperMem(days,costs,i+1,dp);

        int passEndDay=days[i]+7-1;
        int j=i;
        while(j<days.size()&&days[j]<=passEndDay){
            j++;
        }
        int cost7=costs[1]+mincostTicketsHelperMem(days,costs,j,dp);
        passEndDay=days[i]+30-1;
        j=i;
        while(j<days.size()&&days[j]<=passEndDay){
            j++;
        }
        int cost30=costs[2]+mincostTicketsHelperMem(days,costs,j,dp);
        dp[i]= min(cost1,min(cost7,cost30));//here dp[i] is the minimum cost for tickets from that (ith) day until end
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return mincostTicketsHelperMem(days,costs,0,dp);
    }
};
*//solve using tabulation
class Solution {
public:
    int mincostTicketsHelperTab(vector<int>& days,vector<int>& costs){
        vector<int> dp(days.size()+1,-1);
        dp[days.size()]=0;
        for(int i=days.size()-1;i>=0;i--){
            int cost1=costs[0]+dp[i+1];

            int passEndDay=days[i]+7-1;
            int j=i;
            while(j<days.size()&&days[j]<=passEndDay){
                j++;
            }
            int cost7=costs[1]+dp[j];
            passEndDay=days[i]+30-1;
            j=i;
            while(j<days.size()&&days[j]<=passEndDay){
                j++;
            }
            int cost30=costs[2]+dp[j];
            dp[i]= min(cost1,min(cost7,cost30));//here dp[i] is the minimum cost for tickets from that (ith) day until end
        }
        
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        return mincostTicketsHelperTab(days,costs);
    }
};
