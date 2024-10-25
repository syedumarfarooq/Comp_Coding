void createMapping(unordered_map<int,int> & mapping, int inorder[], int n) {
        for(int i=0; i<n; i++) {
                mapping[inorder[i]] = i;
        }
}
Node* buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int &postIndex, int size, 
int inorderStart, int inorderEnd, unordered_map<int,int> &mapping) {
        //basecase
        if(postIndex < 0 || inorderStart > inorderEnd) {
                return NULL;
        }

        //A
        int element = postorder[postIndex];
        postIndex--;
        Node* root = new Node(element);

       // int pos = findPosition(inorder,size, element);//O(n)
        int pos = mapping[element];//O(1)
        //root->right solve
        root->right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, pos+1, inorderEnd, mapping);

        //root->left solve
        root->left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, pos-1, mapping);

        return root;


}
int main() {


        int inorder[] = {40,20,10,50,30,60};
        int postorder[] = {40,20,50,60,30,10};
        int size = 6;
        int postIndex = size-1;
        int inorderStart = 0;
        int inorderEnd = size-1;

        unordered_map<int,int> mapping;

        createMapping(mapping, inorder, size);

        cout << "Building the tree: " << endl;
        Node* root = buildTreeFromPostOrderInOrder(inorder, postorder,postIndex,size, inorderStart, inorderEnd, mapping);

        cout << "Printing the tree " << endl;
        levelOrderTraversal(root);



  
  return 0;
}
