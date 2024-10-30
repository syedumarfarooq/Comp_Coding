*//HOMEWORK***
//2.Check if the tree is complete Binary Tree
        //first by level travesal add pair into the queue <count,node*> then whenever there is no child add null if the parent is null then
        //stop this must have counted all the node + null spaces ,then if the count>total count of the nodes then it is not bst
        // Or
        //RECURSIVEly
        //if only left child true if right child false and if leaf node then true and has both child true
        //using my thinking adding some points if ther is one left only child in that same level there should not be any node after that
        //for this we might have to consider level count and distance count
