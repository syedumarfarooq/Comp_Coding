//1.COUNT PRIMES
// https://leetcode.com/problems/count-primes/description/
// Given an integer n, return the number of prime numbers that are strictly less than n.
// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
// 1)NORMAL METHOD
class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i<n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int count=0;
        if(n==0 || n==1)return 0;
        for(int i=2;i<n;i++){
            if(isPrime(i)){
                count++;
            }
        }
        return count;
    }
};
// 2)REDUCING RANGE
class Solution {
public:
    bool isPrime(int n){
      int sqrtN=sqrt(n)//if n has 2 factors a and b other than 1 and itself so assume a>√ n and b>√ n so this implies ab>n this is not possible as ab=n so one of the factor should be less than √ n so we check if there is any factor that is less than √ n of n  if yes then we say it as non prime as it has more than 2 factors ,by doing this we are reducing the complexity but not that much
        for(int i=2;i<sqrtN;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int count=0;
        if(n==0 || n==1)return 0;
        for(int i=2;i<n;i++){
            if(isPrime(i)){
                count++;
            }
        }
        return count;
    }
};
// 3)SIEVE OF ERATOSHENES(imp theorem for counting prime)
-make a array from 2 to n-1 which represent all number and mark them as true(prime no)
-start from 2 till end mark all the multiples of 2 except 2 as non prime i.e false
-repeat till end where it is true and mark its multiples false
-count the number of prime numbers i.e true
class Solution {
public:
    int countPrimes(int n) {
        if(n==0||n==1) return 0;
        vector<bool> prime(n,true);
        prime[0]=prime[1]=false;
        int ans=0;
        for(int i=2;i<n;i++){
            if(prime[i]){
                ans++;
                int j=2*i;
                while(j<n){
                    prime[j]=false;
                    j=j+i;
                }
            }
        }
        return ans;
    }
};
