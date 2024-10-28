https://www.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/0
// Given an array arr[] of N integers and replace every element with the least greater element on its right side in the array. If there are no greater elements on the right side, replace it with -1. 

// Example 1:

// Input:
// arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28}
// Output: {18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1}
// Explanation: 
// The least next greater element of 8 is 18.
// The least next greater element of 58 is 63 and so on.

*// we are moving from right to left because we are finding the successor as the elements on the right are possible solution we add them first *
*// and update the tree and find the successor as the answer for the current node is already in the tree as we are adding from right to left *
*// and we have to find it in the right side*
class Node{
    public:
    int data;
    Node* left,*right;
    Node(int val):data(val),left(0),right(0){};
};
class Solution{
    public:
    Node* insert(Node* root,int val,int &succ){
        if(!root)return new Node(val);
        if(val>=root->data){
            root->right=insert(root->right,val,succ);
        }else{
            succ=root->data;//if val is lesser than something then only successor can be found
            root->left=insert(root->left,val,succ);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>ans(arr.size(),-1);
        Node* root=0;
        for(int i=arr.size()-1;i>=0;i--){
            int succ=-1;
            root=insert(root,arr[i],succ);
            ans[i]=succ;
        }
        return ans;
    }
};
