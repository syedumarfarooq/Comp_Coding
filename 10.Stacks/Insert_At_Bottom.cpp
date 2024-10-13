// Insert the top element of the stack at the bottom of the same stack
void solve(string<int> &s,int target){
  if(s.empty()){
    s.push(target);
    return;
  }
  int temp=s.top();
  s.pop();
  solve(s,target);
  s.push(temp);
}
void insertAtBottom(string<int> &s){
  if(s.empty()){
    cout<<"stack empty";
    return;
  }
  int target=s.top();
  s.pop();
  solve(s,target);
  
}
