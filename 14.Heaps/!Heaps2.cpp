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
