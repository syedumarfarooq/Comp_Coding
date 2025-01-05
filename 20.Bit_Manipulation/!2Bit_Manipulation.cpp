
*//Question1:check power of 2
*//IMP
//given a number check if the number can be converted in the form of 2 power eg:16 is 2^4
*//logic
//it is a fixed rule that if we perform & AND operation on n and n-1 and if the answer is 0 then n is power of 2
*//code
bool checkPowerOf2(int n){
  if((n&(n-1))==0){
    return true;
  }
  return false;
}
*//Question2:count set bit
//count how many bits are 1 in a number
  *//code brute force
int countSetBits(int n) {
  int count = 0;
  while(n !=0) {
    int lastBit = n & 1;//& operation on the last bit and one will give the bit present in the last bit 
    if(lastBit)//if it is 1 we increment count and perform right shift
      count++;
    //right shift
    n = n >> 1;
  }
  return count;
}
*//logic 
  *//imp
  // in this we are removing the last bit everytime and counting until the number becomes zero
  //if n is 14 i.e 1110 and n-1 will be 1110 what does n-1 do is it will find the last bit which has 1 and convert to 0 then then next element in 1 will be interchanged
  // 1110 the third 1 will be changed to zero as it is last then Flips all bits to the right of it. so th n-1 of 14 will be 1101 as last one is converted to 0 and rest bits are flipped
// eg:n= 8, 1000 ;n-1=0111
  //we are doing this because we keep on removing the last 1 everytime we do n&n-1 
  //eg:n  :1110
    // n-1:1101
  //and perfoming & it will remove the last set bit from the n and count it
  //we do this step until n becomes 0
*//code fast method
int countSetBitsFast(int n) {
  int count = 0;
  while(n != 0) {
    //remove last set bit
    n = (n & (n-1));
    count++;
  }
  return count;
}
*//Question 3: FastExpoention
https://github.com/syedumarfarooq/Comp_Coding/blob/main/4.Pointers/Basic_Maths_for_DSA/*$Fast_Exponentation.cpp
*//Question 4:clear bits in the given range
  //   eg:11010101010101 //we want to remove from 5th index from beginnig to 10th//the given index here is just for reference to to get an idea of the range 
  // mask:111110000001111
  // and if we do AND operation  we will clear all the bits in that range 1&0=0
//now problem is creating mask we can divide this in two parts
// 11111000000000 first part this can be optained by (-1<<(i+1))//as -1 is all 1's if we left shit till i'th index we will get this
// 00000000001111 second part this can be optaned by (1<<j)-1 //as i<<j will create 00000000010000 if we -1 into this it will become 000000000001111
//if we perfrome OR operation on both part we will get 111110000001111
  *//code 
  void clearBitsInRange(int n, int i, int j ) {//here index given in input are from the end i.e the last bit of the n number is consider 0 basically right to left
  int a = (-1 << (i+1)); //first part of the mask
  int b = (1 << j) - 1;//second part of the mask
  int mask = a | b;
  n = n & mask;
  cout << "after clearing in range " << n << endl;
}
*//Question 4:
//a opponent is standing on n'th stare and u are standing at 0th stare u can only climb 2^n number of stares so what is the minimum number of steps to reach oponent
  //and every 2^n step taken is considered as one step
// i.e u can climb either 2,4,8,16.... steps and so 2^2 is also considered one step and 2^4 is also considered one step
*//logic 
  // 2,4,8 are 10,100,1000 respectively if the oponent is standing at 6th position i will take 2 steps i.e 2 and 4 i.e 10+100 which is 6:110 if we count the number of set i.e no of 1 
  // in the end postion we can find number of steps as the end position is total of 2^n steps
//so basically we have to count the number of set of n'th position where oposition is standing 
//we got this intiution as every 2^n number has only one set bit i.e 10,100,1000 bit so the end position  will be the addition of all the steps that is of either 10,100,1000....
// so for every step there will be 1 bit present, in the end position if we find out the number of 1 in the end postion we will know how many 2^n steps it has taken
  //so simply we can use the countsetbits to find the miniumn number of 2^k steps taken to reach the end 
int countSetBitsFast(int n) {
  int count = 0;
  while(n != 0) {
    //remove last set bit
    n = (n & (n-1));
    count++;
  }
  return count;
}
