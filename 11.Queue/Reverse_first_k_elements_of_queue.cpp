void reverseK(queue<int> &q,int k){
  stack<int> s;
  int count=0;
  int n=q.size();
  if(k<=0||k>n){
    return;
  }
  while(!q.empty()){
    int temp=q.front();
    q.pop();
    s.push(temp);
    count++;
    if(count==k){
      break;
    }
  }
  while(!s.empty()){
    int temp=s.top();
    s.pop();
    q.push(temp);
    
  }
  //push n-k from queue to back;
  count=0;
  while(!q.empty() && n-k!=0){
    int temp=q.front();
    q.pop();
    q.push(temp);
    count++;
    if(count==n-k){
      break;
    }
  }
  
}
