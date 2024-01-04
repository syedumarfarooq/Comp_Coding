// Move all negative number to left side of the array
// Assumption:the order of number is not required
// Example:[1,2,-3,4,-5,6]
//         =>[-3,-5,1,6,2,4]// there can be any order but all the negative numbers should be at the left side
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==2){
                swap(nums[high],nums[mid]);
                high--;
            }
            else{
                mid++;
            }
        }
    }
};
