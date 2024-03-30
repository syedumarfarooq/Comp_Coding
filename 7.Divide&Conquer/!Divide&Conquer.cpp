********************************************************// CLASS 1**************************************************************************
//   1.MERGE SORT
    #include <iostream>
    using namespace std;
    void merge(int arr[],int start,int end){
        int mid=start+(end-start)/2;
        int len1=mid-start+1;
        int len2=end-mid;//e-(mid+1)+1
        //dynamically creating a array of length len1 and len2
        int* left =new int[len1];
        int* right=new int[len2];
        //copying values of arr into left arr
        int k=start;
        for(int i=0;i<len1;i++){//O(len1)
            left[i]=arr[k++];
        }
        //copying values of arr into right arr
        k=mid+1;
        for(int i=0;i<len2;i++){//O(len2)
            right[i]=arr[k++];
        }
        //comparing values of left and right array and placing it in the main array
        int leftIndex=0;
        int rightIndex=0;
        int mainArrayIndex=start;
        while(leftIndex<len1&&rightIndex<len2){//O(n)
            if(left[leftIndex]<right[rightIndex]){
                arr[mainArrayIndex++]=left[leftIndex++];
            }
            else{
                arr[mainArrayIndex++]=right[rightIndex++];
            }
        }
        while(leftIndex<len1){//O(len1)
             arr[mainArrayIndex++]=left[leftIndex++];
        }
        while(rightIndex<len2){//O(len2)
             arr[mainArrayIndex++]=right[rightIndex++];
        }
        
    }
    void mergeSort(int arr[],int start,int end){
        if(start>=end){
            return;
        }
        int mid=start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,end);
    }
    int main()
    {
        int arr[]={5,4,3,2,1};
        int n=5;
        mergeSort(arr,0,n-1);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        
        return 0;
    }
Time Complexity:O(nlogn)
// explanation:T(n)=2T(n/2)+nk
//             T(n/2)=2T(n/4)+n/2k}//multiply with 2 so that 2T(n/2) and T(n/2) can get cancelled and also n/2 will become n
//             T(n/4)=2T(n/8)+n/4k}//multiply with 4 so that it can get cancelled and also n/4 will become n
//             .
//             .
//             .
//             T(1)=k+k
//             --------------------//we can derive i from n/2^i=1
//             T(n)=(k)+(i*n*k)//i is the number of iteration of times it is running to reach the final call so n/2^i=1=>i=logn as n is divided by 2 every time for i times the n/2^i will be i
//             T(n)=nlogn
------------LEARN IN PLACE MERGE SORT TO NOT TAKE EXTRA SPACE IN MERGE FUNCTION THAT IS CREATING RIGHT AND LEFT ARRAY-----
// C++ program in-place Merge Sort
#include <iostream>
using namespace std;
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
// Inplace Implementation
void merge(int arr[], int start, int mid, int end)
{
    int start2 = mid + 1;
 
    // If the direct merge is already sorted
    if (arr[mid] <= arr[start2]) {
        return;
    }
 
    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end) {
 
        // If element 1 is in right place
        if (arr[start] <= arr[start2]) {
            start++;
        }
        else {
            int value = arr[start2];
            int index = start2;
 
            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;
 
            // Update all the pointers
            start++;
            mid++;
            start2++;
        }
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
 
        // Same as (l + r) / 2, but avoids overflow
        // for large l and r
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout <<" "<< A[i];
    cout <<"\n";
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printArray(arr, arr_size);
    return 0;
}
********************************************************// CLASS 2**************************************************************************
2.QUICK SORT
    #include <iostream>
using namespace std;
int partition(int arr[],int s,int e){
    //choose pivotElement
    int pivotIndex=s;
    int pivotElement=arr[s];
    int count=0;
    //count the elements less than the pivotElement so that it can be placed to its right position
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivotElement){
            count++;
        }
    }
    //placing the pivotElement to its right position
    int rightIndex=s+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex=rightIndex;
    //the array should contain elements in such a way that the elements smaller than pivot elements should
    //placed on the right and the larger element on the left
    int i=s;
    int j=e;
    while(i<pivotIndex&&j>pivotIndex){
        while(arr[i]<=pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }
        if(i<pivotElement&&j>pivotElement){
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;
    
}
void quickSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    //partition logic and return pivot index
    int p=partition(arr,s,e);
    //pivot element left
    quickSort(arr,s,p-1);
    //pivot element right
    quickSort(arr,p+1,e);
}
int main()
{
    int arr[]={5,4,3,2,1};
    int n=5;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

***********************************************************************************//*****************
