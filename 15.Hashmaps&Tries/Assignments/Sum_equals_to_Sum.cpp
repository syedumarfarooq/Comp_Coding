https://www.geeksforgeeks.org/problems/sum-equals-to-sum4006/1
// Given an array arr. Find if there are two pairs (a, b) and (c, d) such that a+b = c+d.

// Examples:

// Input: arr[] = [3, 4, 7, 1, 2, 9, 8] 
// Output: true
// Explanation: (3, 7) and (9, 1) are the pairs whosesum are equal.  
// Input: arr[] = [65, 30, 7, 90, 1, 9, 8]
// Output: false
// Explanation: There is no pair.
class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        unordered_map<int,int>map;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int sum=arr[i]+arr[j];
                if(map.find(sum)!=map.end()){
                    return true;
                }else{
                    map[sum]=true;
                }
            }
        }
        return false;
    }
};
