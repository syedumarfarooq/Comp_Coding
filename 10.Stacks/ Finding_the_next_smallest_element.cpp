// Finding the next smallest element
// eg:2,1,4,3
//   =>1,-1,3,-1
//   after 2 the next smallest element is 1
//   after 1 there is no  smallest element so -1 
//   after 4 the next smallest element is 3
//   after 3 there is no  smallest element so -1 

Time Complexity:O(n)

vector<int> nextSmallest(vector<int> v){
  stack<int> s;
  s.push(-1);
  vector<int> ans(v.size());
  for(int i=v.size()-1;i>=0;i--){
      int curr=v[i];
      while(s.top()>=curr){
        s.pop();
      }
      ans[i]=s.top();
      s.push(curr);
  }
  return ans;
}
// Finding the prev smallest element
vector<int> nextSmallest(vector<int> v){
  stack<int> s;
  s.push(-1);
  vector<int> ans(v.size());
  for(int i=0;i<=v.size()-1;i--){
      int curr=v[i];
      while(s.top()>=curr){
        s.pop();
      }
      ans[i]=s.top();
      s.push(curr);
  }
  return ans;
}
