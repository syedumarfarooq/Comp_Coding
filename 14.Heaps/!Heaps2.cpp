*//Heap STL(priority_queue)***
#include <iostream>
#include <queue>
using namespace std;
*//MAX HEAP
int main() {
  //max-heap
  priority_queue<int> pq;
  pq.push(3);
  pq.push(6);
  pq.push(9);
  pq.push(4);
  pq.push(8);

  cout << "top element: " << pq.top() << endl;//=>9
  pq.pop();
  cout << "top element: " << pq.top() << endl;//=>8
  pq.pop();
  cout << "top element: " << pq.top() << endl;//=>6
  pq.pop();
  cout << "top element: " << pq.top() << endl;//=>4
  pq.pop();
  cout << "top element: " << pq.top() << endl;//=>3
  pq.pop();
  cout << "Size: " << pq.size() << endl;//=>0
  if(pq.empty()) {
          cout << "Max heap is empty" << endl;
  }
  else {
          cout << "Max heap is not empty" << endl;
  }
 return 0;
}
*//MIN HEAP

int main() {
        //min-heap
        priority_queue<int,vector<int>, greater<int> > pq;
        pq.push(3);
        pq.push(6);
        pq.push(9);
        pq.push(4);
        pq.push(8);

        cout << "top element: " << pq.top() << endl;//=>3
        pq.pop();
        cout << "Size: " << pq.size() << endl;//=>4
        cout << "top element: " << pq.top() << endl;//=>4
        pq.pop();
        cout << "top element: " << pq.top() << endl;//=>6
        pq.pop();
        cout << "top element: " << pq.top() << endl;//=>8
        pq.pop();
        cout << "top element: " << pq.top() << endl;//=>9
        pq.pop();

          if(pq.empty()) {
          cout << "Min heap is empty" << endl;
  }
  else {
          cout << "Min heap is not empty" << endl;
  }

        return 0;
}
*//Tip**
// Generally kth smallest, kth greatest, merge k sorted array and merge ke sorted LL (where ever k types questions)generally these questions
// can be solved using in heap but not ALL no logical reason just based on expierence
*//HW**
// 1.convert a bst(it is already complete) into max heap 
        //inorder of bst will give u a ascending ordered list using this place them using postorder eg:1,2,3 first place 1 on left 2 on right
        //then three as main node
//2.check if the tree is complete
        //first by level travesal add pair into the queue <count,node*> then whenever there is no child add null if the parent is null then
        //stop this must have counted all the node + null spaces ,then if the count>total count of the nodes then it is not bst
        // Or
        //RECURSIVEly
        //if only left child true if right child false and if leaf node then true and has both child true
        //using my thinking adding some points if ther is one left only child in that same level there should not be any node after that
        //for this we might have to consider level count and distance count
