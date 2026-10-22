https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/description/
// same logic as the 3886. sum of sortables 
//in this we use the concatenate two array to check if on rotation if the array becomes sorted this is a simple method to find if rotating can sort
//in this we have checked both increasing and decreasing after rotation if it is increasing we find the ith index were the sorted subpart ends from 
// there we minus the length of the main array so that we can see how many rotation we need to get it sorted eg; 312, 312312, so the sorted part ends
// at 3th index so if we add plus one(bcz indexing starts from 0 ) and minus the length of the array which is 3 u will get 4-3 =1 so if we rotate 312
//once we will get 123 
//for decreasing we have to add one more opertion which is to reverse so in the result we add +1
//There are two ways to solve this problem first reverse then solve or directly solve some cases give different answer for both so we take the min
//eg:102 if first solved 102102 we need 2 operation for rotating to make it in decreasing order then +1 operation for reverese so total 3,
//if we first reversed it which 201 which takes one operation , then solve 201201 we need 1 operation to rotate to make it in reverse order so total 
// 2
//so in the main function we consider both the possiblity and take the minimum


class Solution {
public:
    int solve(vector<int>& nums){
        vector<int> temp=nums;
        for(int v: nums){
            temp.push_back(v);
        }
        int count=1;
        //increasing
        for(int i=1;i<temp.size();i++){
            if(temp[i]>temp[i-1]){
                count++;
            }else{
                count=1;
            }
            if(count==nums.size()){
                return (i+1)-nums.size();
            }
        }
        //decreasing
        count=1;
        for(int i=1;i<temp.size();i++){
            if(temp[i]<temp[i-1]){
                count++;
            }else{
                count=1;
            }
            if(count==nums.size()){
                return (i+1)-nums.size()+1;
            }
        }
        return 1e9;// we are taking the max number not the -1 bcz in main we want the minimum number if it return 1e9 it means no solution found
    }
    int minOperations(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int ans=solve(nums);
        
        reverse(nums.begin(),nums.end());//this reverse step operation cost not added, added in next line
        ans=min(ans,solve(nums)+1);//+1 for the reverse operation which we did in previous step
        return ans==1e9?-1:ans;

    }
};
