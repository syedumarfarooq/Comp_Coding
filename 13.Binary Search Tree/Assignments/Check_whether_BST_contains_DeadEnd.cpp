https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
*//For a node to be dead end 
  *//1.it should be a leaf node
  *//2.if the tree contains the next and previous number then that node is a dead end
//   Given a Binary Search Tree that contains unique positive integer values greater than 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means a leaf node, at which no other node can be inserted.

// Example 1:

// Input :   
//                8
//              /   \ 
//            5      9
//          /  \     
//         2    7 
//        /
//       1     
          
// Output : 
// Yes
// Explanation : 
// Node 1 is a Dead End in the given BST.
class Solution{
  public:
    void fun(Node* root,unordered_map<int,bool> &visited,bool &ans){
        if(root==NULL){
            return;
        }
        visited[root->data]=1;
        if(root->right==NULL&&root->left==NULL){
            int xp1=root->data+1;//x plus 1 i.e next number
            int xm1=root->data-1==0?root->data:root->data-1;
            if(visited.find(xp1)!=visited.end()&&visited.find(xm1)!=visited.end()){
                ans=true;
                return;
            }
        }
        fun(root->left,visited,ans);
        fun(root->right,visited,ans);
    }
    bool isDeadEnd(Node *root)
    {
        bool ans=false;
        unordered_map<int,bool> visited;
        fun(root,visited,ans);
        return ans;
    }
};
