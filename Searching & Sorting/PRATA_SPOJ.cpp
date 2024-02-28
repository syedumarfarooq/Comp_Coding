// https://www.spoj.com/problems/PRATA/
// IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank
// R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata) (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence
// in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.
// -----for example if 5 paratas are give to ranked chef he does it in =>R*(1+2+3+4+5)=>r*(n*(n+1)/2)
// Input
// The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

// Output
// Print an integer which tells the number of minutes needed to get the order done.

// Example
// Input:
// 3
// 10
// 4 1 2 3 4
// 8
// 1 1
// 8
// 8 1 1 1 1 1 1 1 1

// Output:
// 12
// 36
// 1
bool isPossibleSol(vector<int>&cooksrank,int sol,int nP){
    int currentParanta=0;
    for(int i=0;i<cooksrank.size();i++){
       int timeTaken=0;
       int j=1;//where j is the paranta no of each cook
       int R=cooksrank[i];
       while(true){
        if(timeTaken+j*R<=sol){
          currentParanta++;
          timeTaken+=j*R;
          j++;
        }
        else{
          break;
        }
       }
      if(currentParanta>=nP){
        return true;
      }
    }
  return false;
}
  
int solve(vector<int>&cooksrank,int nP){//where nP are no of paratas
  sort(cooksrank.begin(),cooksrank.end());
  int s=0;
  int e=cooksrank[cooksrank.end()-1]*(np*(np+1)/2);//r*(n*(n+1)/2);
  int ans=-1;
  while(s<=e){
    int mid=s+(e-s)/2;
    if(isPossibleSol(cooksrank,mid,nP){
        ans=mid;
        e=mid-1;
    }
    else{
      s=mid+1;
    }
  }
  return ansl
}
