// CLASS 1
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
        for(int i=0;i<len1;i++){
            left[i]=arr[k++];
        }
        //copying values of arr into right arr
        k=mid+1;
        for(int i=0;i<len2;i++){
            right[i]=arr[k++];
        }
        //comparing values of left and right array and placing it in the main array
        int leftIndex=0;
        int rightIndex=0;
        int mainArrayIndex=start;
        while(leftIndex<len1&&rightIndex<len2){
            if(left[leftIndex]<right[rightIndex]){
                arr[mainArrayIndex++]=left[leftIndex++];
            }
            else{
                arr[mainArrayIndex++]=right[rightIndex++];
            }
        }
        while(leftIndex<len1){
             arr[mainArrayIndex++]=left[leftIndex++];
        }
        while(rightIndex<len2){
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
