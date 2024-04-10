https://leetcode.com/problems/combination-sum-ii/description/
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
]
class Solution {
public:
    void combinationSum2Helper(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int>&output,int index){
        if(target==0){
            ans.push_back(output);
            return;
        }
        if(target<0){
            return;
        }
        if(index>=candidates.size()){
            return;
        }
     //mapping can also be used to solve this problem of handling duplicates
     //unordered_map<int,bool>visited;
     //the concept behind this two numbers should not be same at the same level then duplicates forms
        for(int i=index;i<candidates.size();i++){
            if(i>index&&candidates[i]==candidates[i-1]){ //}     if(visited.find(candidates[i])!=visited.end()){continue;}
                continue;                                //}or 
            }                                            //}     visited[candidates[i]]=true;
            output.push_back(candidates[i]);
            combinationSum2Helper(candidates,target-candidates[i],ans,output,i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>output;
        sort(candidates.begin(),candidates.end());
        combinationSum2Helper(candidates,target,ans,output,0);
        return ans;
    }
};
