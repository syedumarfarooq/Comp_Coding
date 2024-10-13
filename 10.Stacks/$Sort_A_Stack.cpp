void insertSort(stack<int>&s,int target){
  if(s.empty()){
    s.push(target);
    return;
  }
  if(s.top()>=target){
    s.push(target);
    return;
  }
  int topElement=s.top();
  s.pop();
  insertSort(s,target);
  s.push(topElement);
  
}
void SortStack(stack<int> &s){
  if(s.empty()){
    return;
  }
  int topElement=s.top();
  s.pop();
  SortStack(s);
  insertSort(s,topElement);
}
