// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// SAME AS BOOK ALLOCATION
// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

// The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


// Example 1:

// Input:
// n = 5
// k = 3
// arr[] = {5,10,30,20,15}
// Output: 35
// Explanation: The most optimal way will be:
// Painter 1 allocation : {5,10}
// Painter 2 allocation : {30}
// Painter 3 allocation : {20,15}
// Job will be done when all painters finish
// i.e. at time = max(5+10, 30, 20+15) = 35
// Example 2:

// Input:
// n = 4
// k = 2
// arr[] = {10,20,30,40}
// Output: 60
// Explanation: The most optimal way to paint:
// Painter 1 allocation : {10,20,30}
// Painter 2 allocation : {40}
// Job will be complete at time = 60

class Solution
{
  public:

bool isPossibleSolution(int arr[],int n,int k,long long sol){
        long long  timeSum=0;//keep count of page number
        int count=1;//keeps count of students
        for(int i=0;i<n;i++){
            if(arr[i]>sol){
                return false;
            }
            if(timeSum+arr[i]>sol){
                timeSum=0;
                timeSum+=arr[i];
                count++;
                if(count>k){
                    return false;
                }
            }
            else{
                timeSum+=arr[i];
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {    long long s=0;
    long long e=0;
        for(int i=0;i<n;i++){
            e+=arr[i];
        }
        
        long long  ans=-1;
       
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(isPossibleSolution(arr,n,k,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
    
};
