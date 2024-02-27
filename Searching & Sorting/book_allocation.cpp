// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

// Example 2:

// Input:
// N = 3
// A[] = {15,17,20}
// M = 2
// Output:32
// Explanation: Allocation is done as
// {15,17} and {20}
class Solution 
{
    public:
    bool isPossibleSolution(int A[],int N,int M,int sol){
        int pageSum=0;//keep count of page number
        int count=1;//keeps count of students
        for(int i=0;i<N;i++){
            if(A[i]>sol){
                return false;
            }
            if(pageSum+A[i]>sol){
                pageSum=0;
                pageSum=pageSum+A[i];
                count++;
                if(count>M){
                    return false;
                }
            }
            else{
                pageSum+=A[i];
            }
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {   int s=0;
        int e=accumulate(A,A+N,0);//add all the elements in the array and 0 is the initial starting point so it starting adding array to 0
        
        int ans=-1;
        if(M>N){
            return -1;//if students are more than books -1 as all students must be allocated
        }
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossibleSolution(A,N,M,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};

