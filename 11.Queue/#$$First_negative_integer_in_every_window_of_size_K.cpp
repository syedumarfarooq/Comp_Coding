// for every window of k elements find first negative number
*// This is solved using sliding window******
// eg:12,-1,-7,8,-15,30,16,28 k=3
//   =>-1,-1,-7,-15,-15,0
void solve(int arr[],int n,int k){ //n is size of array
  deque<int> q;
  //process first window of size K
  for(int i=0;i<k;i++){
    if(arr[i]<0){
      q.push_back(i);//saving the index not the element because to check where the element lies within the window
    }
  }
  //remaining window process
  for(int i=k;i<n;i++){
    //printing answer of previous window before shifting the window
    if(q.empty()){
      cout<<0;
    }else{
      cout<<arr[q.front()];
    }
    //deleting out of windows elements
    while((!q.empty())&&(i-q.front()>=k)){
      q.pop();
    }
    if(arr[i]<0){
      q.push_back(i);
    }
  }
  //printing answer of last window as we print answer of previous window and shift the window so the last window is not printed
  if(q.empty()){
    cout<<0;
  }else{
    cout<<arr[q.front()];
  }
}
