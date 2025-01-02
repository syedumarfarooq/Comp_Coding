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
  https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
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
class Solution {
  public:
  bool static cmp(pair<int,int> a, pair<int,int> b) {//sorting them in decreasing using the profit weight ration
  double ratio1 = ((1.0)*a.first) / a.second;
  double ratio2 = ((1.0)*b.first) / b.second;
  return ratio1 > ratio2;
}
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
                 vector<pair<int,int> > data;
          for(int i=0; i<val.size(); i++) {
            data.push_back({val[i], wt[i]});
          }
        
          sort(data.begin(), data.end(), cmp);
          double totalValue = 0.0;
          //check eac items k entire itm lelu ya frraction lu
          for(int i=0;i<data.size(); i++) {
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
              double valueToAdd = ratio * capacity;
              totalValue += valueToAdd;
        
              //udpate capacity;
              capacity = 0;//we used up all the capacity
              break;
             }
        }
        return totalValue;
    }
};
*//Question 6
https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
// Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
//       i. Each student gets exactly one packet.
//      ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.
// Examples:
// Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
// Output: 6
// Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following m packets :[3, 4, 9, 7, 9].
*//logic
  // in this we are using sliding window first we sort all the chocolate packets
  //as for the difference to be minimum the elements (minimum and maximum) should be closer to each other for the difference to be little
  //so that is why we sort and apply sliding window method 
//then we make a window of size =  no. of students then the first element of the window will be the minimum and the last element will be 
  //maximum
//we start finding the difference of all the window by shifting one value then return the minimum difference
*//code
  class Solution {
  public:
    int findMinDiff(vector<int>& arr, int m) {
        // code here
        int n=arr.size();
        sort(arr.begin(), arr.end() );

      //check differences in m-size window
      int i = 0;
      int j = m-1;
      int diff = INT_MAX;
      while(j<n) {
        int newDiff = arr[j] - arr[i];
        diff = min(diff, newDiff);
        j++;
        i++;
      } 
      return diff;
    }
};
