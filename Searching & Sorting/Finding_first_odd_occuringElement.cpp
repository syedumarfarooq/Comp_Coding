// Find the odd occuring element inside array
// Example:[1,1,2,2,3,3,4,5,5,3,3]
// Output:4
// *two same number should be adjacent
// *if there are more than one adjacent pairs they need not be adjacent 
// *inside the array only one odd occuring element is present
#include <iostream>
#include<vector>
using namespace std;

int solve(vector<int> arr) {
  int s = 0;
  int e = arr.size() - 1;
  int mid = s + (e-s)/2;

  while(s <= e) {
    if(s == e) {
      //single element
      return s;
    }

    //2 cases -> mid - even or mid - odd
    if(mid%2 == 0 ) {
      if(arr[mid] == arr[mid + 1] ) {
        s = mid + 2;
      }
      else {
        e = mid;
      }
    }
    else {
        if(arr[mid] == arr[mid-1]) {
          s = mid + 1;
        }
        else {
          e = mid - 1;
        }
    }
    mid = s + (e-s)/2;
  }
  return -1;
}

int main() {
  vector<int> arr{1,1,2,2,1};
  int ans = solve(arr);
  cout << "index is " << ans << endl;
  cout << "value is " << arr[ans] << endl;

  return 0;
}
