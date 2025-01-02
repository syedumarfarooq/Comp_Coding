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
*//Question 3
//  “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.
// The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.
//  Help Theodore write a program that calculates the penalty of the given position.
// Input
// The first line of the input file contains the number of test cases.
// Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).
// Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).
// Output
// For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.
*//logic
 // in this we have to find  the largest rectangle that is not defended so we will find the maximum difference between two rows and colums between the towers so that we can multiply
 // and find number of boxes
// eg: in 5x5 the towers are on 1,1 and  4,3 the  difference between towers  (i.e from one tower to another)is 2 and 1 so 3 boxes are the  boxes undefended 
 //so like that we have to consider all possible chances and get maximum among them
 //we also have to consider the rectangle from the starting colum to next tower what if they make bigger rectangle for that we keep reference points an imaginary tower
 //at 0 and 6 which are out of bound 
#include <iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int main() {
  int x, y, n;
  cin >> x >> y >> n;
  int t = n;
  vector<int> rowC;
  vector<int> colC;

  rowC.push_back(0);//pushing the starting element also as tower because to find refernce of the starting point
  colC.push_back(0);//indexing starts from 1 so if we want the number of rows or column between two points b-a-1

  while(t--) {
    int a, b;
    cin >> a >> b;
    rowC.push_back(a);
    colC.push_back(b);
  }

  //size of 2D grid
  rowC.push_back(x+1);//pushing the ending element also as tower because to find refernce of the ending point
  colC.push_back(y+1);//size +1 as if we want to find distance between 2 points i.e from 2 to end i.e we have to minus 6-2-1 to get three so we add +1 to the end as we can find the max
  sort(rowC.begin(), rowC.end());//they can be in any order so sorting them to find difference between each other so we can find max difference and largest box possible
  sort(colC.begin(), colC.end());

  int maxLen = INT_MIN;
  for(int i=1; i<rowC.size(); i++) {
      int a = rowC[i-1];
      int b = rowC[i];

      maxLen = max(maxLen, b-a-1);
  }

  int maxWidth = INT_MIN;
  for(int i=1; i<colC.size(); i++) {
      int a = colC[i-1];
      int b = colC[i];

      maxWidth = max(maxWidth, b-a-1);
  }

  cout << "answer is " << maxLen * maxWidth << endl;

  return 0;
}
//input
// 15 8 3
//  3 8
//  11 2
//  8 6
