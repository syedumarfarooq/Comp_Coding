// https://leetcode.com/problems/minimum-time-difference/description/
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
// Example 1:

// Input: timePoints = ["23:59","00:00"]
// Output: 1
// Example 2:

// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(int i=0;i<timePoints.size();i++){
            string time=timePoints[i];
            int hrs=stoi(time.substr(0,2));
            int mins=stoi(time.substr(3,2));
            int totalMins=(hrs*60)+mins;
            minutes.push_back(totalMins);
        }
        sort(minutes.begin(),minutes.end());
        int mini=INT_MAX;
        for(int i=1;i<minutes.size();i++){
            int diff=minutes[i]-minutes[i-1];
            if(diff<mini){
                mini=diff;
            }
        }
        int lastdiff=minutes[0]+1440-minutes[minutes.size()-1];//this case is for the last time for example if the last time is 23:59 and the first time is 00:00 but the actual difference is 1439 but according to time the difference is 1 so we check only  the last and first if the difference is minimum 
        return min(mini,lastdiff);
    }
};
