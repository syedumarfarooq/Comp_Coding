https://www.hackerrank.com/challenges/ctci-merge-sort/problem
// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

// Example 1:

// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 
// has three inversions (2, 1), (4, 1), (4, 3).
// Example 2:

// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already 
// sorted so there is no inversion count.
long merge(vector<int>&arr,vector<int>& temp,int start,int end){
        int mid=start+(end-start)/2;
        int i=start,j=mid+1,k=start;
        long c=0;
        while(i<=mid&&j<=end){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }else{
                temp[k++]=arr[j++];
                c+=mid-i+1;
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=end){
            temp[k++]=arr[j++];
        }
        while(start<=end){
            arr[start]=temp[start];
            ++start;
        }
        return c;
    }
    long mergeSort(vector<int>&arr,vector<int>& temp,int start,int end){
        if(start>=end){
            return 0;
        }
        int mid=start+(end-start)/2;
        long  c=0;
        c+=mergeSort(arr,temp,start,mid);
        c+=mergeSort(arr,temp,mid+1,end);
        c+=merge(arr,temp,start,end);
        return c;
    }
long countInversions(vector<int> arr) {
        long c=0;
        vector<int>temp(arr.size(),0);
        c=mergeSort(arr,temp,0,arr.size()-1);
        
        return c;
}
