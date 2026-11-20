//first we iterate through every element and let recursion find us the next consecutive element
//we pass the every element with 0 and 1 increament then find the next consecutive element
//finding the next consecutive element means if a element is x we will find either x(finding equal next consequtive element becuase we can 
// increment it by one) or x+1(finding the next consequtive elemement), then we move forward by letting the recursion do its work

*//Mysolution
  class Solution {
public:
    vector<vector<int>> mem;
    int findNextIndex(int s,int val, vector<int>& nums){
        int e=nums.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==val){
                ans=mid;
                e=mid-1;
            }
            if(nums[mid]<val){
                s=mid+1;
            }else{
                e=mid-1;
            }

        }
        return ans;
    }
    int solve(int i,int inc,vector<int>& nums){
        if(mem[i][inc]!=-1)return mem[i][inc];
        int currval=nums[i]+inc;
        int len=1;
        int j=findNextIndex(i+1,currval,nums);
        if(j!=-1){
            len=max(1+solve(j,1,nums),len);
        }
        j=findNextIndex(i+1,currval+1,nums);
        if(j!=-1){
            len=max(1+solve(j,0,nums),len);
        }
        return mem[i][inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        mem.assign(nums.size()+1,vector<int>(2,-1));
        int result=1;
        for(int i=0;i<nums.size();i++){
             result=max({solve(i,0,nums),solve(i,1,nums),result});
        }
        return result;
    }
};






/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion Memoization)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);

        if(j < n && nums[j] == target) {
            return j;
        }

        return -1;
    }

    int solve(int i, int inc, vector<int>& nums) {

        if(memo[i][inc] != -1) {
            return memo[i][inc];
        }

        int currVal = nums[i] + inc; //inc = 0/1
        int len = 1;

        //1st Option = find (currVal+1)
        int j = findMethod(nums, i+1, currVal+1);
        if(j != -1) {
            len = max(len, 1 + solve(j, 0, nums));
        }

        //2nd Option = find (currVal) and then inc by +1
        j = findMethod(nums, i+1, currVal);
        if(j != -1) {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return memo[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(begin(nums), end(nums));

        memo.assign(n+1, vector<int>(2, -1));

        int result = 1;
        for(int i = 0; i < n; i++) {
            result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
        }

        return result;
    }
};


//Approach-2 (Bottom Up)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();
        if (j < n && nums[j] == target)
            return j;

        return -1;
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        dp.assign(n + 1, vector<int>(2, 0));

        int result = 1;


        for (int i = n - 1; i >= 0; i--) { //O(n * log(n))
            for (int inc = 0; inc <= 1; inc++) {

                int currVal = nums[i] + inc;
                int len = 1;

                //1st Option = find (currVal+1)
                int j = findMethod(nums, i + 1, currVal + 1);
                if (j != -1) {
                    len = max(len, 1 + dp[j][0]);
                }

                //2nd Option = find (currVal) and then inc by +1
                j = findMethod(nums, i + 1, currVal);
                if (j != -1) {
                    len = max(len, 1 + dp[j][1]);
                }

                dp[i][inc] = len;
                result = max(result, len);
            }
        }

        return result;
    }
};
