// A int array is given which contains number by using that number you have to find the targer by adding and give the minimum elements required to reach targer
// eg:target:3 arr=[1,2]
//   output=>2
// Explaination:1+1+1=3 [1,1,1] 3 elements required to reach the target
//              1+2=3   [1,2]   2 elements required to reach the target
//              2+1=3   [2,1]  2 elements required to reach the target
//             so the minimum elements required is two
  
#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
int solve(vector<int>& arr,int target){
    if(target==0){
        return 0;//to reach targer 0 you need 0 elements
    }
    if(target<0){
        return INT_MAX;//we are using int_max because it goes in negative so it is invalid
    }
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++){
        int ans=solve(arr,target-arr[i]);
        if(ans!=INT_MAX){//int_max is only used because if we add 1 to int_max it will go out of range
            mini=min(mini,ans+1);//when base condition is reached it returns 0 and to count every step or every element one is added or else it will return 0 for every function
        }
    }
    return mini;
}
int main()
{
  vector<int> arr{1,2};
  int target=5;
  int ans=solve(arr,target);
  cout<<"ans:"<<ans;
  return 0;

    return 0;
}
