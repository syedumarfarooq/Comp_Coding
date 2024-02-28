//https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

// Example 1:

// Input: N = 5
// Output: 120
// Explanation : 5! = 1*2*3*4*5 = 120
// Example 2:

// Input: N = 10
// Output: 3628800
// Explanation :
// 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> ans;
        ans.push_back(1);
        int carry=0;
        for(int i=2;i<=N;i++){
            for(int j=0;j<ans.size();j++){
                int x=ans[j]*i+carry;
                ans[j]=x%10;
                carry=x/10;
            }
            while(carry){
                ans.push_back(carry%10);
                carry/=10;
                
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
