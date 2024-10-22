*//Trees******
Non-liner type of data structure
*//Binary Tree******
A trees which has only atmost 2 children nodes 
-If a tree only has left children or only right children then they are call *//Skew tree**
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
  }
};
Node* buildTree(){
  int data;
  cout<<"enter data:";
  cin>>data;
  if(data==-1){
    return NULL;
  }
  Node* root=new Node(data);
  root->left=buildTree();
  root->right=buildTree();
  return root;
}
*//Level Order Traversal*******
void levelOrderTraversal(Node* root){
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left){
      q.push(temp->left);
      
    }
    if(temp->right){
      q.push(temp->right);
      
    }
  }
}
int main(){
  Node* root=NULL;
  root=buildTree();
}
