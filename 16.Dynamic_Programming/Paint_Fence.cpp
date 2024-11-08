// The problem states that there are ’n’ fences which can be coloured with one of the ‘k’ colours in such a way that not more than two
// adjacent fences have the same colour.In how many ways can we colour it with ‘k’ colours?
// eg:n=3(no of fences) k=2(no colors) =>6 differnt ways to color them
*//Intiution
//   for n=2 XX(fences),either both can be same or different if they are same then eg: k=3 
//   RR,GG,BB if same and RG,RB,GB,GR,BR,BG if different
// here for n=3 XXX , we are taking last two fences and they can either be same or different and the first fence is left for recursion to handle
//   eg:k=3  if same RBB, RGG,BRR,BGG,GRR,GBB and if different RRB,RRG,BBR,BBG,GGR,GGB,RBR,RBG,GBR,GBG,RGR,RGB,BRB,BRG,BGR,BGB,GRB,GRG
//   same for n=4 XXXX, we are taking last two fences and they can either be same or differnt
//   for n=4 for first 2 f(2) fence will be taken care by recursion but the next two can be same or differnt
//   1)if same f(2)*(k-1) for every element of f(2) we cannot add all three colors for eg:first two are RG we cannot put GG so 
//     for every f(2) we multiply with k-1 orelse it can make 3 adjecent fences which 
//   2)if different f(3)*k-1 for EVERY element of f(3) we cannot add all three colors what if there are already 2 same present in f2
// so,f(4)=f(2)*(k-1)+f(3)*(k-1)
//    f(4)=(f(2)+f(3))*(k-1)
//    f(n)=[f(n-2)+f(n-1)]*(k-1)
//   I got a doubt for f(4) what if f(3) is all different colors can we can multiply with all three colors so k-1 will not work
//   answer for the doubt is that if there k-1 multiply with f(3) but f(4) is not made with singlt f(3) it is made with f(2) the rest
// one element is present in that f(2)*k-1 for some elements  which are same for eg:GBRG,GBRB is present in f(3)*(k-1) and GBRR is present in 
// f(2)*(k-1) as we are diving the same and different in two coloumns
#include<iostream>
using namespace std;
*//Using recursion TLE
// int solveUsingRecursion(int n,int k){
//   if(n==1){//if there is only one fence then it can be painted in only k different ways
//     return k;
//   }
//   if(n==2){
//     return (k+k*(k-1));//if there are two fence if both are same they can be painted in k differnt ways and if both are different then
//     //k*(k-1)ways bcz every color mathes with every other color
//   }
//   int ans=(solveUsingRecursion(n-2,k)+solveUsingRecursion(n-1,k))*(k-1);
//   return ans;
// }
int main(){
  int n=4;
  int k=3;
  int ans=solveUsingRecursion(n,k);
  cout<<"ans:"<<ans<<endl;
  return 0;
}
