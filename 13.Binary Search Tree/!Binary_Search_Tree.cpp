*//BST******
// for every node
// 1.root->data>left subtree data
// 2.root->data<right subtree data
Node* insertIntoBST(Node* root, int data) {

        if(root == NULL) {
                //this is the first node we have to create
                root = new Node(data);
                return root;
        }

        //no the first node 

        if(root-> data > data) {
                //insert in left
                root->left = insertIntoBST(root->left, data);
        }
        else {
                //insert into right
                root->right = insertIntoBST(root->right, data);
        }
        return root;
}

void takeInput(Node* &root) {
        int data;
        cin >> data;

        while(data != -1) {
                root = insertIntoBST(root, data);
                cin >> data;
        }
}
void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
		
		
	}
}
void preOrderTraversal(Node* root) {
	//NLR
	if(root == NULL)
		return;

	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
*//Inorder of a BST is always sorted**
void inOrderTraversal(Node* root) {
	//LNR
	if(root == NULL)
		return;

	inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	//LRN
	if(root == NULL)
		return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << " ";
}

int main() {
	  Node* root = NULL;
	  cout << "Enter the data for Node " << endl;
	  takeInput(root);
	  cout << "Printing the tree" << endl;
	  levelOrderTraversal(root);
}
