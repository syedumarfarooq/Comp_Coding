*//check if a number is odd or even
  // using this bcz modulus is lil heavy operation
int main() {
  int n = 50;
  if(n & 1) {//last bit and if & operation is performed on it if the last bit is 1 then the &1 will 1
    cout << "n is odd" << endl;
  }
  else {
    cout << "n is even" << endl;
  }
}
*//get i'th bit of a number
  //in this we create a mask i.e on the i'th bit we place 1 and rest all 0 and if & operation is performed we will know if it 1 or 0
  // number:000000......0001010
  // mask:  000000......0001000
  //        -------------------
  //        000000......0000000
int getithBit(int n , int i) {
  int mask = 1 << i;//this multiplies 1 by 2 i times i.e it move the 1 i times to the left //the indexing starts from right and 0 
  int ans = n & mask;
  if(ans == 0)
    return 0;
  else
    return 1;
}
*//set i'th bit
  //if the i't bit is zero it will change it to 1 
void setithBit(int n, int i) {
  int mask = 1 << i;
  int ans = n | mask;
  cout << "after setting: " << ans << endl;
}
*//clear i'th bit
  // if the i'th bit is 1  it will make it to zero
void clearIthBit(int& n, int i) {
  int mask = ~(1<<i);//this will make a mask which on i'th bit has 0 and rest all 1, if the i'th bit has 1 and after performing the & operation with mask the i'th bit will become 0
  n = n & mask;
  
}
*//update i'th bit based on given input
  //in this we are making a mask in which the i'th bit has the target and we perform OR 
  //if the i'th bit is 0 and the target is 1 or 0 the above method with work perfectly
  //if there is 1 in the i'th bit then the above method wont work so we clear that bit and make 0 then perform the operation
void updateIthBit(int& n, int i, int target) {
  clearIthBit(n,i);//if the i'th element is 1 we clear it and make it 0 
  int mask = target << i;//i'th bit will have either 0 or 1 depending on target
  n = n | mask;
  cout << "after updating " << n << endl;
}
