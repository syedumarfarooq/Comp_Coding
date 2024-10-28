https://www.geeksforgeeks.org/problems/median-of-bst/1
*//We are using morris travel to find the count and also the median we are using this because to strictly keep the space complexity O(1)***
// Given a Binary Search Tree of size N, find the Median of its Node values.

// Example 1:

// Input:
//        6
//      /   \
//    3      8   
//  /  \    /  \
// 1    4  7    9
// Output: 6
// Explanation: Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8, 9. So, here median will 6.
int findNodeCount(Node* root) {//MorrisInorderTraversal
        int count=0;
        Node* curr=root;
        while(curr){
            //left node is null then visit it and go right
            if(curr->left==nullptr){
                count++;
                curr=curr->right;
            }//left node is not null
            else{
                //find inorder predecessor
                Node* pre=curr->left;
                while(pre->right!=curr&&pre->right){//if pre->right==curr then it is already connected the curr to pred so no need to find the pred and remove the link as we  have already visited
                    pre=pre->right;
                }
                //if pre->right is null then  go left after establishing the link from pred to curr
                if(pre->right==nullptr){
                    pre->right=curr;
                    curr=curr->left;
                }
                //left is already visited,go right after visiting curr node,while removing the link
                else{
                    pre->right=nullptr;
                    count++;
                    curr=curr->right;
                }
            }
        }
        return count;
    }
float findActualMedian(Node* root,int n) {//MorrisInorderTraversal
        int i=0;
        int odd1=(n+1)/2;
        int odd1Val=-1;
        int even1=n/2;
        int even1Val=-1;
        int even2=(n/2)+1;
        int even2Val=-1;
        Node* curr=root;
        while(curr){
            //left node is null then visit it and go right
            if(curr->left==nullptr){
                i++;
                if(i==odd1)odd1Val=curr->data;
                if(i==even1)even1Val=curr->data;
                if(i==even2)even2Val=curr->data;
                curr=curr->right;
            }//left node is not null
            else{
                //find inorder predecessor
                Node* pre=curr->left;
                while(pre->right!=curr&&pre->right){//if pre->right==curr then it is already connected the curr to pred so no need to find the pred and remove the link as we  have already visited
                    pre=pre->right;
                }
                //if pre->right is null then  go left after establishing the link from pred to curr
                if(pre->right==nullptr){
                    pre->right=curr;
                    curr=curr->left;
                }
                //left is already visited,go right after visiting curr node,while removing the link
                else{
                    pre->right=nullptr;
                    i++;
                    if(i==odd1)odd1Val=curr->data;
                    if(i==even1)even1Val=curr->data;
                    if(i==even2)even2Val=curr->data;
                    curr=curr->right;
                }
            }
        }
        float median=0.0;
        if((n&1)==0){
            //even
            median=(even1Val+even2Val)/2.0;
        }else{
            //odd
            median=odd1Val;
        }
        return median;
    }
float findMedian(struct Node *root)
{
      int n=findNodeCount(root);
      
      return findActualMedian(root,n);
}
