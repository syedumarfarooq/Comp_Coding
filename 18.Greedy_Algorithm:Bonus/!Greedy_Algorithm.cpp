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
