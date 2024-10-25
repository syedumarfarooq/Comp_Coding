// A sum tree is that every nodes data is changed into the sum of left branch+right branch and the node data
int convertToSum(Node* root){
       if(root==NULL){
           return 0;
       }
       int leftAns=convertToSum(root->left);
       int rightAns=convertToSum(root->right);
       root->data=root->data+leftAns+rightAns;
       return root->data;
   }
