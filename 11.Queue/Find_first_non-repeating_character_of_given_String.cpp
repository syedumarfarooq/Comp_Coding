// eg:zarcaazrd
// =>zzzzzzrcc
// eg:aabc
//   =>a#bb
// Queue is used to track characters and there can be multiple characters which are frequency one but we want the first one so FIFO ordering so 
// Queue will work
string solve(string s){
  int freq[26]={0};
  queue<char> q;//tracking potential answers
  string ans="";
  for(int i=0;i<s.length();i++){
    char ch=s[i];
    freq[ch-'a']++;
    q.push(ch);
    while(!q.empty()){
      if(freq[q.front()-'a']>1){//if freq of top is greater than 1 pop and go to next element
        q.pop();
      }else{
        ans.push_back(q.front());
        break;
      }
    }
    if(q.empty()){
      ans.push_back('#');
    }
  }
  return ans;
}
