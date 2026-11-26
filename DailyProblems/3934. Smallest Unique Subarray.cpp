
class Solution {
public:
    int MOD = 1e9+7;
        typedef long long ll;

    ll findPower(ll a, ll base) {//most efficient way to find powers of larger number in logn time
        if (base == 0) {
            return 1;
        }

        ll half = findPower(a, base / 2);
        ll result = (half * half) % MOD;
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }
    bool check(vector<int>& nums,int size, int base){
        int i=0;
        int j=0;
                ll p = findPower(base, size-1); //O(log(size))
int n = nums.size();

        ll hash = 0;
        unordered_map<ll, int> mp;
        while(j<nums.size()){
hash = (hash * base + nums[j]) % MOD;
            if(j-i+1<size){
                j++;
            }else{
                mp[hash]++;
                 hash = (hash - (p * nums[i])%MOD + MOD) % MOD;
                i++;
                j++;
            }
        }
        for(auto &it:mp){
            if(it.second==1)return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int l=1;
        int r=nums.size();
        int result=0;
int base = *max_element(begin(nums), end(nums)) + 1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(nums,mid,base)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
};
