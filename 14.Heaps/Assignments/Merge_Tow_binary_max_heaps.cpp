https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

// Example 1:

// Input  : 
// n = 4 m = 3
// a[] = {10, 5, 6, 2}, 
// b[] = {12, 7, 9}
// Output : 
// {12, 10, 9, 2, 5, 7, 6}
class Solution{
    public:
    void heapify(vector<int> &c,int i,int&n){
        while(true){
            int left=2*i+1;
            int right=2*i+2;
            int swapindex=i;
            if(left<n&&c[left]>c[swapindex]){
                swapindex=left;
            }
            if(right<n&&c[right]>c[swapindex]){
                swapindex=right;
            }
            if(swapindex==i){
                break;
            }
            swap(c[swapindex],c[i]);
            i=swapindex;
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> c(a.begin(),a.end());
        c.insert(c.end(),b.begin(),b.end());
        for(int i=(c.size()/2)-1;i>=0;i--){
            int n=c.size();
            heapify(c,i,n);
        }
        return c;
    }
};
