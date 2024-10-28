https://www.interviewbit.com/problems/valid-bst-from-preorder/
*//Reference:
// You are given a preorder traversal A, of a Binary Search Tree.

// Find if it is a valid preorder traversal of a BST.

// Note: Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.
  void build(int &i,int min,int max,vector<int> &A){
        if(i>=A.size()){
            return ;
        }
       
        if(A[i]>min&&A[i]<max){
            int rootdata =A[i++];
            build(i,min,rootdata,A);//we are setting a range and adding them
            build(i,rootdata,max,A);
        }
        
    }
int solve(int* A, int n1) {
    int min=INT_MIN;int max=INT_MAX;
        int i=0;
        return build(i,min,max,A);
        return i==A.size();
}
