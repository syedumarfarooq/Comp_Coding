https://www.geeksforgeeks.org/problems/quick-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high)return;
        //this is another method to partition a arr so that all element greater than pivot are
        //on the right side and smaller are placed on the left and pivot is placed in the right
        //place
        int i=low-1;
        int j=low;
        int pivot=high;
        while(j<pivot){
            if(arr[j]<arr[pivot]){
                ++i;
                swap(arr[i],arr[j]);
            }
            ++j;
        }
        ++i;
        swap(arr[i],arr[pivot]);
        quickSort(arr,low,i-1);
        quickSort(arr,i+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        //WONT USE THIS IN THIS METHOD
    }
};


