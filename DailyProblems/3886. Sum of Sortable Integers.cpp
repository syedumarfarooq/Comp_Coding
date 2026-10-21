https://leetcode.com/problems/sum-of-sortable-integers/
// this question has n going up until 10^5 so our tice complexity should be around o(n) to O(nlogn)
// This Question is solved in 3 steps
//   1.find all the divisor which is divisible by n (it takes O(√n) time complexity as we check for 1 to k*k<=n)
//   2.we are checking we a sub array can be sorted after rotating by placing the same subarray twice if we find a sorted subarray in that 2 subarray whose size is >=k then we can say it is sorted if rotated eg: 675, 675675 in this the 567 is sorted so this is possible
//   3.then to check if all the subarray are sorted after the step 2 we take two subarray and save both min and max of the subarray if the max of 1st subarray is less than min of 2nd subarray then it is sorted

class Solution {
public:
    bool check(vector<int>& temp){
        vector<int> v=temp;
        for(int i: temp){
            v.push_back(i);
        }
        int count=1;
        for(int i=1;i<v.size();i++){
            if(v[i-1]>v[i]){
                count=1;
            }else{
                count++;
            }
            if(count>=temp.size()){return true;}
        }
        
        return false;
    }
    int sortableIntegers(vector<int>& nums) {
        int ans=0;
        vector<int> divisor;
        for(int i=1;i*i<=nums.size();i++){
            if(nums.size()%i==0){
                divisor.push_back(i);
                // cout<<i;
                if(i*i!=nums.size()){
                    divisor.push_back(nums.size()/i);
                    // cout<<nums.size()/i;
                }
                
            }
        }

        for(int k: divisor){
            int prevMin=INT_MAX;
            int prevMax=INT_MIN;
            int currMin=nums[0];
            int currMax=nums[0];
            int flag=true;
             vector<int> temp;
            for(int i=0;i<nums.size();i++){
                // cout<<i;
                currMin=min(currMin,nums[i]);
                currMax=max(currMax,nums[i]);
                temp.push_back(nums[i]);
            
                if((i+1)%k==0){
                    // cout<<k;
                    cout<<k<<prevMax<<currMin<<" . ";
                    if(!check(temp)||prevMax>currMin){
                        
                        // cout<<check(temp)<<k<<" .";
                        flag=false;
                        temp.clear();
                        break;
                    }
                    temp.clear();
                    prevMin=currMin;
                    prevMax=currMax;
                    currMin=INT_MAX;
                    currMax=INT_MIN;
                }
             
            }
            if(flag){
                // cout<<k<<" ";
                ans+=k;
            }
        }
        return ans;
    }
};
