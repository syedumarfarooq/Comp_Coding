// CLASS 1
// Binary Search
//   it is only applicable if its elements are in  monotonic order(increasing or decreasing)
    int binarysearch(int arr[], int n, int k) {
        // code here
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            if(arr[mid]==k){
                return mid;
            }
            else if(arr[mid]>k){
                end=mid-1;
            }else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return -1;
    }
    // Time-Complexity:n->n/2->n/4->....1
    //                 (n/2^k)=1
    //                 n=2^k
    //                 log2(n)=klog2(2)[base 2 and 2 get cancelled]
    //                 logn=k[log of base 2 is considered as log]
    //                 O(k)=O(logn)
    // TC:[logn]
// STL for Binary Search
//   #include<algorithm>
//   binary_search(v.begin(),v.end(),key);{where v is vector<int> v;}
// CLASS 2
// Applying binary search to 2d array
#include <iostream>
using namespace std;

bool binarySearch(int arr[][4], int rows, int cols, int target) {
  int s = 0;
  int e = rows*cols - 1;
  int mid = s + (e-s)/2;

  while(s <= e) {
    int rowIndex = mid/cols;//formula to access row number using a single index 
    int colIndex = mid%cols;//formula to access column number using a single index 
    
    if(arr[rowIndex][colIndex] == target) {
      cout << "Found at " << rowIndex <<" " << colIndex << endl;
      return true;
    }

    if(arr[rowIndex][colIndex] < target) {
      s = mid +1;
    }
    else {
      e = mid - 1;
    }
    mid = s + (e-s)/2;
  }
  return false;
}

int main() {
  int arr[5][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20}};
  int rows = 5;
  int cols = 4;

  int target = 99;

  bool ans = binarySearch(arr,rows,cols, target);

  if(ans) {
    cout << "Found " << endl;
  }
  else {
    cout << "not Found" << endl;
  }




  return 0;
}
// CLASS 3
// Types of question in binary search
// 1.Classic question(lower bound,upper bound,pivot,peak,search in rotated sorted,total occurence,square root etc)
// 2.Search space question(finding answers in search space)(aggressive cow etc)
// 3.Index Observation question(finding odd occurence in an array)
//CLASS 4
Sorting Techniques
i)Selection sort
