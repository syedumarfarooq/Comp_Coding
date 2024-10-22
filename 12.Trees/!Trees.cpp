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
void levelOrderTraversalprintinginlevel(Node* root){//printing the node in level wise eg:1
                                                                        //2 3
  queue<Node*> q;
  q.push(root);
  q.push(NULL);//after first root node inserting null then whenever null comes will push null 
  //after this it will iterate all its children and all to the queue after all its childre it will come on NULL when NULL comes we are adding 
  //NULL again telling the end of all the children of current level
  while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    if(temp==NULL){//
      cout<<endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }else{
      cout<<temp->data<<" ";
    if(temp->left){
      q.push(temp->left);
      
    }
    if(temp->right){
      q.push(temp->right);
      
    }
    }
    
  }
}
void inOrderTraversal(Node* root){
  if(root==NULL){
    return ;
  }
  inOrderTraversal(root->left);
  cout<<root->data;
  inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root){
   if(root==NULL){
    return ;
  }
  cout<<root->data;
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
  if(root==NULL){
    return;
  }
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout<<root->data;
}
int main(){
  Node* root=NULL;
  root=buildTree();
}
