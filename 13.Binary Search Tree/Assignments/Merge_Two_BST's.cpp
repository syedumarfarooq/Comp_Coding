*//Similar to Brothers_From_Different_Roots.cpp**
https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
// Given two BSTs, return elements of merged BSTs in sorted form.

// Examples :

// Input:
// BST1:
//        5
//      /   \
//     3     6
//    / \
//   2   4  
// BST2:
//         2
//       /   \
//      1     3
//             \
//              7
//             /
//            6
// Output: 1 2 2 3 3 4 5 6 6 7
// Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
  *//Space Complexity:O(H)where H is the height of the tree
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        stack<Node*> s1,s2;
        vector<int> ans;
        Node* a=root1,*b=root2;
        while(a||b||!s1.empty()||!s2.empty()){
            while(a){
                //inorder traversal
                s1.push(a);
                a=a->left;
            }
            while(b){
             //inorder traversal
                s2.push(b);
                b=b->left;
            }
            if(s2.empty()||(!s1.empty()&&s1.top()->data<=s2.top()->data)){
                auto atop=s1.top();
                ans.push_back(atop->data);
                s1.pop();
                a=atop->right;
            }else{
                auto btop=s2.top();
                ans.push_back(btop->data);
                s2.pop();
                b=btop->right;
                
            }
        }
        return ans;
    }
};
