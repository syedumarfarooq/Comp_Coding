//https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// Implement pow(x, n) % M.
// In other words, given x, n and M, find (xn) % M.
 

// Example 1:

// Input:
// x = 3, n = 2, m = 4
// Output:
// 1
// Explanation:
// 32 = 9. 9 % 4 = 1.
// Example 2:

// Input:
// x = 2, n = 6, m = 10
// Output:
// 4
// Explanation:
// 26 = 64. 64 % 10 = 4.
// ---------------FOR LITTLE MORE EXPLANATION LOOK INTO FAST EXPONENETIAL IN THE SAME FOLDER---------------
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int ans=1;
		    while(n>0){
		        if(n&1){
		            ans=(ans*x)%M;//whenever performing big operation the value can go out of range so we mod the value in every step to reduce the range so that it can fit
		        }
		        x=(x*x)%M;//whenever performing big operation the value can go out of range so we mod the value in every step to reduce the range so that it can fit
		        n>>=1;
		        
		    }
		    return ans%M;//whenever performing big operation the value can go out of range so we mod the value in every step to reduce the range so that it can fit
		}

};
// TimeComplexity:O(logb)
