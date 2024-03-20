// Input : abc
// Output : a, b, c, ab, bc, ac, abc," "
void printSubsequence(string str,string output,int i){
  if(i>=str.length()){
    cout<<output<<endl;//the contains the answer
  }
  //exclude
  printSubsequence(str,output,i+1);//if you are excluding then your and send the same output string
  //include
  output.push_back(str[i]);//if you want to include then you concatinate str[i] into the string and then go to next step
  printSubsequence(str,output,i+1);//or printSequence(str,output+str[i],i+1);
}
int main(){
  string str="abc";
  string output="";
  int i=0;
  printSubsequence(str,output,i);
  return 0;
}

