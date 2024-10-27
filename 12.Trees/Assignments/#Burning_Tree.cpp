https://www.geeksforgeeks.org/problems/burning-tree/1
// Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
// Note: The tree contains unique values.


// Examples : 

// Input:      
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10
// Target Node = 8
// Output: 7
// Explanation: If leaf with the value 8 is set on fire. 
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree.
class Solution {
  public:
    Node* makeNodetoParentMappingAndFindTargetNode(Node* root,unordered_map<Node*,Node*>&parentMap,int target){
        queue<Node*>q;
        Node* targetNode=0;
        q.push(root);
        parentMap[root]=0;
        while(!q.empty()){
            Node* front=q.front();q.pop();
            if(front->data==target){
                targetNode=front;
            }
            if(front->left){
                q.push(front->left);
                parentMap[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                parentMap[front->right]=front;
            }
        }
        return targetNode;
    }
    int burnTheTree(Node* targetNode,unordered_map<Node*,Node*> &parentMap){
        unordered_map<Node*,bool> isBurnt;//already burnt
        queue<Node*> q;//currently set on fire nodes
        int T=0;
        q.push(targetNode);
        isBurnt[targetNode]=1;
        while(!q.empty()){
            int size=q.size();
            bool isFireSpreaded=0;
            for(int i=0;i<size;i++){
                Node* front=q.front();q.pop();
                if(front->left&&!isBurnt[front->left]){
                    q.push(front->left);
                    isBurnt[front->left]=1;
                    isFireSpreaded=1;
                }
                if(front->right&&!isBurnt[front->right]){
                    q.push(front->right);
                    isBurnt[front->right]=1;
                    isFireSpreaded=1;
                }
                if(parentMap[front]&&!isBurnt[parentMap[front]]){
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]]=1;
                    isFireSpreaded=1;
                }
            }
            if(isFireSpreaded){
                ++T;
            }
        }
        return T;
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> parentMap;//node->parentNode
        Node* targetNode=makeNodetoParentMappingAndFindTargetNode(root,parentMap,target);//create map for every parent node and also find the target node
        return burnTheTree(targetNode,parentMap);
    }
};
