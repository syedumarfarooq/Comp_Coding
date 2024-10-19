*//Using stack*****
void reverseQueue(queue<int> &q){
  stack<int> s;
  while(!q.empty()){
    int element=q.front();
    q.pop();
    s.push(element);
  }
  while(!s.empty()){
    int element=s.top();
    s.pop();
    q.push(element);
  }
}
*//Using recursion*****
void reverseQueue(queue<int> &q){
  if(q.empty()){
    return;
  }
  int element=q.front();
  q.pop();
  reverseQueue(q);
  q.push(element);
}
