// Using preorder and Inorder build a tree
int findPosition(int arr[], int n, int element) {
        for(int i=0; i<n; i++) {
                if(arr[i] == element) {
                        return i;
                }
        }
        return -1;
}

Node* buildTreeFromPreOrderInOrder(int preorder[],int inorder[],int size,int &preIndex,int inorderStrt,int inorderEnd){
  if(preIndex>=n||inorderStrt>inorderEnd){
    return NULL:
  }
  int element=preorder[preIndex++];
  Node* root=new Node(element);
  int pos=findPosition(inorder,size,element);
  root->left=buildTreeFromPreOrderInOrder(preorder,inorder,size,preIndex,inorderStrt,pos-1);
  root->right=buildTreeFromPreOrderInOrder(preorder,inorder,size,preIndex,pos+1,inorderEnd);
  return root;
}
int main(){
  // int inorder[] = {40,20,50,10,60,30,70};
        // int preorder[] = {10,20,40,50,30,60,70};
        // int size = 7;
        // int preIndex = 0;
        // int inorderStart = 0;
        // int inorderEnd = size-1;

        // cout << "Building Tree: " << endl;
        // Node* root = buildTreeFromPreOrderInOrder(inorder, preorder,size, preIndex, inorderStart, inorderEnd );

        // cout<< endl << "Printing level order traversal " << endl;
        // levelOrderTraversal(root);//do on your own
}
