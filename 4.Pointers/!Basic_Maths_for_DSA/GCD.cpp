// https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// Given two positive integers a and b, find GCD of a and b.

// Note: Don't use the inbuilt gcd function

// Example 1:

// Input: 
// a = 3
// b = 6
// Output: 3
// Explanation: GCD of 3 and 6 is 3

// Example 2:

// Input: 
// a = 1
// b = 1
// Output: 1
// Explanation: GCD of 1 and 1 is 1
//Formula:Gcd(a,g)=gcd(a-b,b) a>b or  gcd(a%b,b) a>b //we are not using mod as modular operation are heavy operation compared to subtraction
//                 gcd(b-a,a) a<b  or gcd(b%a,a) a<b
// compute this until on of the values become zero then the other number is gcd
class Solution {
  public:
    int gcd(int a, int b) {
        if(a==0)return b;
        if(b==0)return a;
        while(a>0 && b>0){
            if(a>b){
                a=a-b;
            }else{
                b=b-a;
            }
        }
        return a==0 ? b : a;
        
    }
};


