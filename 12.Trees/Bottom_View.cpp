void printBottomView(Node* root) {
        if(root == NULL )
                return;
        
        ///create a map for storing HD -> TopNode ->data
        map<int, int> topNode;

        //Level Order
        //we will store a pair consisting of Node and Horizontal Distance
        queue< pair<Node*, int> > q;
        q.push(make_pair(root, 0));

        while(!q.empty()) {//using level traversal 
                pair<Node*, int> temp = q.front();
                q.pop();

                Node* frontNode = temp.first;
                int hd = temp.second;

              
			
            
                topNode[hd] = frontNode->data;
                

                if(frontNode -> left)
                        q.push(make_pair(frontNode->left, hd-1));

                if(frontNode -> right)
                        q.push(make_pair(frontNode->right, hd+1));
        }

        //ab aapka answer store hua hoga aapke map me 
        cout << "Printing the answer: " << endl;
        for(auto i: topNode) {
                cout << i.first << " -> " << i.second << endl;
        }
}
