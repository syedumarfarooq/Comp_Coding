// Input : abc
// Output : a, b, c, ab, bc, ac, abc," "
INCLUSION AND EXCLUSION PATTERN USED
void printSubsequence(string str,string output,int i){
  if(i>=str.length()){
    cout<<output<<endl;//the contains the answer
    return;
  }
  //exclude
  printSubsequence(str,output,i+1);//if you are excluding then your and send the same output string
  //include//do not write the code for include first as it changes the output values
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
//without recursion can be solved using bitmasking H.W
