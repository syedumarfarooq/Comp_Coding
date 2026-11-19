//in this question we are ignoring the low bcz we are making any two elements equal which makes the low as 0
//to find maximum we are considering three case(after sorting)
// 1.if we make the last two elements same as nums[n-3], then to find max diff we use first element and n-3th element , nums[n-3]-nums[0] 
// 2. if we make the first two elemetns same as n[2], then to find max diff we last element and the 2nd element, nums[n-1]-nums[2]
// 3. if we make the first one elment same as n[1] and the last element same as n[n-2], then to find max differet we need n[n-2] element and the n[1], nums[n-2]-nums[1]
//from these which ever is minimum we return 
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return min({nums[n-3]-nums[0],nums[n-1]-nums[2],nums[n-2]-nums[1]});
    }
};
