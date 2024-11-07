*//Dynamic Programming***
  //booti;past se sikho , dp is a programming technique jo ek baar calculate kr chuke ho, use dubara calculate krne ki need nahi hai
// booti:dp will optimise the code and improve the time complexity but one thing, u once caluculated to forget it store it somewhere
// Building Dp solution using these 3 phases
// 1.Top-down
//   recurrsion+memoisation
// 2.Bottom-Up
//   tabulation method
// 3.Space Optimisation
//   make it O(1) not possible for every question but will try
*//When to Apply DP***
// 1.overlapping sub problems(same problem ko baar baar solve kar raha ho)
// 2.Optimal Substructure(optimal solution of bigger problem can be calculated using optimal solution of smaller problem)
// if both of these conditions exist in the question then we use dp 
// eg:1)fibonaci numbers using recurssion f(n)=f(n-1)+f(n-2)
//                      f(5)
//                     /    \
//                    f(4)  f(3)//here f(3) is repeating so overlapping sub poblem when once f(3) is calculated no need for calculating on more time
//                   / \    /   \
//               f(3) f(2) f(2) f(1)
//             / \     / \  / \   / \
//         f(2) f(1)f(1)f(0)........
//   2)f(n) optimal solution can be built from optimal solution of f(n-1) and f(n-2) optimal substructure
*//How to code* 
int fib(int n){//basic recursion code
   if(n==0|n==1){
    return n;
   }
  int ans=fib(n-1)+fib(n-2);
  return ans;
}
*// converting into dp*
// 1.add memoisation(storing answer and fetch if needed)
  // 1.1 create dp array or map or any data structure when u can store answer, and know the length and what should it be intialized with
      // eg:for fibonacci code vector<int> dp(n+1,-1); as f(n) is traversing from 0 to n
  //1.2 store answer in dp
      //eg:fibonnaci code replace ans with dp[n]=fib(n-1)+fib(n-2);
          //return dp[n]
  //1.3 right after base case write one condition i.e to check if answer already exist
      //eg:fibonnace if(dp[n]1=-1)return dp[n] // that is if answer exist do not calculate then directly return answer


      
      
