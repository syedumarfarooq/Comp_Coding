*//try huffman encoding similar to below problem
*//Question 4
  https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
// Minimum Cost rope
// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 
*//logic
  // in this we are using greedy method by joing the minimum length ropes first then the next and so on
  //we use min heap as it returns minimum element in O(1)
  class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int> > pq; 
        for(int i=0; i<arr.size(); i++) {
            pq.push(arr[i]);
        }
        int cost = 0;
        while(pq.size() != 1) {//will do processing until there is one element left 
            int first = pq.top();//fetching the first minimum element
            pq.pop();
            int second = pq.top();//fetching the second minimum element
            pq.pop();
        
            cost += first + second;//adding it to the cost 
            int newLength = first + second;//adding the joined rope back to the pq
            pq.push(newLength);
        
          }
          return cost;
    }
};
*//Question 5
// Fraction Knapsack
// Given the weights and profits of N items, in the form of {profit, weight} put these items in a knapsack of capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, we can break items for maximizing the total value of the knapsack.
// Input: arr[] = {{60, 10}, {100, 20}, {120, 30}}, W = 50
// Output: 240 
// Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. 
// Hence total price will be 60+100+(2/3)(120) = 240
*//logic
// 1.we are using the profit/weight value for each items i.e if profit is 60 and 10 weight then the profit/weight value is 6 so we want
// the maximum profit with least weight so  using  the profit/weight we will sort them in decreasing order
// 2.then we choose every item and check if the weight can be accomodated by remaining knapsack capacity then we use the entire item
// if not we will take fraction of it for example if 20 weight is left and we have a item of 30 weigth and 120 profit 
// we will find the profit/weight ratio (i.e 120/30 =4 ; 4*20(remaining weight)=80 ,so 80 will be added ) and then multiply with the remaining weight
*//code
// #include <iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {//sorting them in decreasing using the profit weight ration
  double ratio1 = ((1.0)*a.first) / a.second;
  double ratio2 = ((1.0)*b.first) / b.second;
  return ratio1 > ratio2;
}

int main() {
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int n= 3;
  int capacity = 50;

  vector<pair<int,int> > data;
  for(int i=0; i<n; i++) {
    data.push_back({val[i], wt[i]});
  }

  sort(data.begin(), data.end(), cmp);
  int totalValue = 0;
  //check eac items k entire itm lelu ya frraction lu
  for(int i=0;i<n; i++) {*// in this code we might get an error and it is a silly mistake told by the instructor to solve it by the running
    // fine for basic text case the instructor gave hit it might be type casting error not garuented
    pair<int,int> item = data[i];
    int itemValue = item.first;
    int itemWeight = item.second;
    //entire inclusioon wala case
    if(itemWeight <= capacity) {
      //add kardo value ko
      totalValue += itemValue;
      //update krdo capacity ko
      capacity = capacity - itemWeight;
    }
    else {
      //fraction include krdo
      //update value
      double ratio = ((1.0)*itemValue) / itemWeight;
      int valueToAdd = ratio * capacity;
      totalValue += valueToAdd;

      //udpate capacity;
      capacity = 0;//we used up all the capacity
    }
  }
  cout << "Answer is: "<< totalValue << endl;
  return 0;
}
