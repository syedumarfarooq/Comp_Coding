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
