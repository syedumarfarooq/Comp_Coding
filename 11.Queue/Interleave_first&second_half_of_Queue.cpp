// eg:1,2,3,4,5,6,7,8,9,10
//   =>1,6,2,7,3,8,4,9,5,10
void interleaveQueue(queue<int> q){
  int n=q.size();
  if(q.empty()){return ;}
  int k=n/2;
  int count=0;
  queue<int> q2;
  //dividing the queue into 2 and adding into new
  while(!q.empty()){
    int temp=q.front();
    q.pop();
    q2.push(temp);
    count++;
    if(count==k){
      break;
    }
    
  }
  //interleaving
  while(!q.empty()&&!q2.empty()){
    int first=q2.front();
    q2.pop();
    q.push(first);
    int second=q.front();
    q.pop();
    q.push(second);
  }
  //if length is odd one more element is left
  if(n&1){
    int element=q.front();
    q.pop();
    q.push(element);
  }
}
