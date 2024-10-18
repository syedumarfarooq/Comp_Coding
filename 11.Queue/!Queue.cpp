*// Queue******
#include<queue>
int main(){
  queue<int> q;
  q.push(10);
  q.push(20);
  cout<<q.size();
  q.pop();//=>10
  if(q.empty()){
    cout<<"queue is empty";
  }else{
    cout<<"queue not empty":
  }
  cout<<"queue front element"<<q.front();
}
*//Queue without stl******
class Queue{
  
};
