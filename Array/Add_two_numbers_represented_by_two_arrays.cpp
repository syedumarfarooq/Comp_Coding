// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-two-arrays2408/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// Given two array A[0….N-1] and B[0….M-1] of size N and M respectively, representing two numbers such that every element of arrays represent a digit. For example, A[] = { 1, 2, 3} and B[] = { 2, 1, 4 } represent 123 and 214 respectively. The task is to find the sum of both the numbers.

// Example 1:

// Input : A[] = {1, 2}, B[] = {2, 1}
// Output : 33
// Explanation:
// N=2, and A[]={1,2}
// M=2, and B[]={2,1}
// Number represented by first array is 12.
// Number represented by second array is 21
// Sum=12+21=33
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
    // Complete the function
    int i=n-1;
    string ans;
    int j=m-1;
    int carry=0;
    int x;
    while(i>=0 and j>=0){
        x=a[i]+b[j]+carry;
        int digi=x%10;
        ans.push_back(digi+'0');
        carry=x/10;
        i--;j--;
    }
     while(i>=0){
        x=a[i]+0+carry;
        int digi=x%10;
        ans.push_back(digi+'0');
        carry=x/10;
        i--;
    }
     while(j>=0){
        x=0+b[j]+carry;
        int digi=x%10;
        ans.push_back(digi+'0');
        carry=x/10;
        j--;
    }
    if(carry){
        ans.push_back(carry+'0');
    }
    while(ans[ans.size()-1]=='0'){
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends
