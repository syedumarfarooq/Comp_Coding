// Why do we use 10! × 10 as the maximum product?

// ### Why do we use `10! × 10` as the maximum product?
// * Every array element is between 1 and 10.
// * Since **LCM is the least common multiple**, we know that LCM cannot exceed `10!`, because `10!` is guaranteed to be a common multiple 
// of every number from 1 to 10. It might not be the least common multiple, but it gives us a safe upper bound.
// * GCD cannot exceed 10 because no array element is greater than 10.

// * For a valid subarray, we know:
//   `Product = LCM × GCD`

// * Therefore, the maximum possible product of a valid subarray is bounded by:
//   `10! × 10 = 36,288,000`

// **Why do we use** `**break**`**?**
// As we extend the subarray, its product never decreases because all elements are positive integers. Once the product exceeds `36,288,000`, 
// it cannot become valid again by adding more elements.
// Therefore, we use `break` to avoid unnecessary calculations.

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0;
        int maxLcm=36288000;//10!*10
        for(int i=0;i<nums.size();i++){
            int product=1;
            int l=1;
            int g=0;
            for(int j=i;j<nums.size();j++){
                product*=nums[j];
                if(product>maxLcm)break;
                l=lcm(l,nums[j]);
                g=gcd(g,nums[j]);
                if(product==l*g){
                    ans=max(ans,(j-i+1));
                }
            }
        }
        return ans;
    }
};
