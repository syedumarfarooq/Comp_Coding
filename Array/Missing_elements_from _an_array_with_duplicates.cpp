// Given an array which ranges from from 1 to n-1 which has a duplicate number, Find the missing number
// Example:[1,3,5,3,4]
// Output:2(missing number)
//1)marking negative method
// void findMissing(vector<int> nums){
//   for(int i=0;i<nums.size();i++){
//       index=abs(nums[i]);
//       if(nums[index-1]>0){
//         nums[index-1]*=-1;
//       }
//   }
//   for(int i=0;i<nums.size();i++){
//     if(nums[i]>0){
//       return i+1;
//     }
// }
2)swapping the elements to its right index then checking if the index matches if not it is the missing element
