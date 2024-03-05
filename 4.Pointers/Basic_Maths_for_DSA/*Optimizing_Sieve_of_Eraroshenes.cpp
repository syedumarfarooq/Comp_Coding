// 1)OPTIMIZING SIEVE OF ERATOSHENES(imp theorem for counting prime)
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
        for(int i=2;i*i<=n;i++){//Optimization 2 
          //as i*i if the i>√n it will go out of range for eg:n=25 if anything greather than 5 will not be iterated as 6*6=36>25
            if(prime[i]){
                ans++;
                //int j=2*i;
              int j=i*i;//Optimization 1
              //first unmarked number would be i*i as others have been marked by 2 to(i-1)eg:6 is marked by 2 so no need to mark it again in 3
                while(j<n){
                    prime[j]=false;
                    j=j+i;
                }
            }
        }
        return ans;
    }
};
//Time complexity:O(nlog(logn))
//as the inner loop has(n/2+n/3+n/5+n/7+.....)=>log(logn)
