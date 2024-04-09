// a array is give of time int
// return the maximum sum of subsequence in which no two elements are adjacent
// Example:[2,1,4,9]
  // output:11=>9+2=11
#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
void solve(vector<int>& arr,int i,int sum,int& maxi){
    if(i>=arr.size()){
        maxi=max(maxi,sum);
        return;
    }
    //include
    solve(arr,i+2,sum+arr[i],maxi);
    //exclude
    solve(arr,i+1,sum,maxi);
}
int main()
{
  vector<int> arr{2,4,1,9};
  int sum=0;
  int maxi=INT_MIN;
  int i=0;
  solve(arr,i,sum,maxi);
  cout<<maxi;

    return 0;
}
