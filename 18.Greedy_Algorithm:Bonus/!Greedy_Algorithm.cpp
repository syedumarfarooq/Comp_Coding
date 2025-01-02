*//Question 1 there are n trains and one platform and only one train can access the platfrom at a time so what the maximum number of train it can accomodate in a day
  *//similar question active selection, one meeting in a room , n trains in a platform
  //in this we are sorting the timings in departure timing and accomodating the first train then check the next train arrival time if it greater than the current departure time 
  // then it will counted and further on
// #include <iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
  return a.second < b.second;
}

int solve(int n, int arr[], int dept[]) {
  vector< pair<int, int> > data;
  for(int i=0; i<n; i++) {
    data.push_back({arr[i], dept[i]});
  }

  sort(data.begin(), data.end(), cmp);


  int cnt = 1;//we are counting the first train irrespictive of the optimal solution this is called greedy method 
  cout << data[0].first << ", "<< data[0].second << endl;
  int lastDept = data[0].second;
  for(int i=1; i<n; i++) {
    if(data[i].first >= lastDept) {//compare every train with previous included train
      //current train can be included
      cnt++;
      lastDept = data[i].second;
      cout << data[i].first << ", "<< data[i].second << endl;    }
  }
  return cnt;
}

// int main() {
//   int n = 4;
//   int arr[] = {5,8,2,4};
//   int dept[] = {7,11,6,5};

//   int ans = solve(n, arr, dept) ;
//   cout << "Answer is:  " << ans << endl;


//   return 0;
// }
*//Question 2
 https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1
//  In a candy store, there are n different types of candies available and the prices of all the N different types of candies are provided to you. You are now provided with an attractive offer.
// For every candy you buy from the store and get K other candies ( all are different types ) for free. Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the n different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the n different candies.
// In both the cases you must utilize the offer i.e. you buy one candy and get k other candies for free.
 
class Solution
{
public:
    int findMin(int candies[],int N,int K){
        int buy=0;
        int free=N-1;
        int amount=0;
        while(buy<=free){
            amount+=candies[buy];
            buy++;
            int count=K;
            while(count!=0 &&free>=buy){
                count--;
                free--;
            }
            
        }
        return amount;
    }
    int findMax(int candies[],int N,int K){
        int buy=N-1;
        int free=0;
        int amount=0;
        while(free<=buy){
            amount+=candies[buy];
            buy--;
            int count=K;
            while(count!=0 && free<=buy){
                count--;
                free++;
            }
            
        }
        return amount;
    }
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int mini=findMin(candies,N,K);
        int maxi=findMax(candies,N,K);
        return {mini,maxi};
    }
};
