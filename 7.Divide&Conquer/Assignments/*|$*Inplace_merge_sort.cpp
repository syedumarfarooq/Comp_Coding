https://leetcode.com/problems/sort-an-array/submissions/1228091069/
INPLACE MERGE SORT
class Solution {
public:
void mergeInPlace(vector<int>& arr, int l, int m, int r)//O(nlogn)
    {   int total_len=r-l+1;
        int gap=total_len/2+total_len%2;//=>ceil(total_len/2)
        while(gap>0){
            int i=l,j=l+gap;
            while(j<=r){
                if(arr[i]>arr[j]){
                    swap(arr[i],arr[j]);
                }
                ++i,++j;
            }
            gap=gap<=1?0:gap/2+(gap%2);//=>ceil(gap)/2)
        }
       
    }
    
    void mergeSort(vector<int>& arr, int l, int r)
    {
        if(l>=r)return ;
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        mergeInPlace(arr,l,m,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};
