// A rod is given of length N and length x,y,z are given the rod can be cut into the lengths of x,y,z and the rod has to be cut in such a way that it has maximum segments using x,y,z
// Example:N=7
//   x=5,y=2,z=2
//   output=>2
//   Explanation:5,2
//   2)N=8
//   x=3,y=3,z=3
//   output=>0
//   3)N=3
//   x=1,y=2,z=3
//   output=>3
#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
int solve(int n,int x,int y,int z){
    if(n==0){
        return 0;//if length of the rod is 0 then it can be cut into 0 seqments
    }
    if(n<0){
        return INT_MIN;//we are using int_min because it goes in negative then it is invalid
    }
    int ans1=solve(n-x,x,y,z)+1;//when base condition is reached it returns 0 and to count every step or every segment one is added or else it will return 0 for every function
    int ans2=solve(n-y,x,y,z)+1;
    int ans3=solve(n-z,x,y,z)+1;
    int ans=max(ans1,max(ans2,ans3));
    return ans;
}
int main()
{
  int n=7;
  int x=5,y=2,z=2;
  int ans=solve(n,x,y,z);
  if(ans<0){//if ans is less than 0 then it is an invalid ans and it cannot be cut 
      ans=0;
  }
  cout<<"ans:"<<ans;
  

    return 0;
}
