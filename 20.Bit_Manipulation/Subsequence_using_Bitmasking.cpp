*//creating subsequence using bit masking
// eg:abc n=3
// =>" ",a,b,c,ab,bc,ca,abc
*//logic
  // we will first run loop from 0 to 2^n because 2^n is the number when converted to binary  gives us bits equal to number of character 
//if we run from 0 to 2^n we will get all the combination i.e subsequence
// if n=3 then 2^3 =8 and loop < 8 i.e 0-7 which will create 000,001,010,011,100,101,110,111 so we will map every bit to every character of 
// string and if there is 0 bit we will ignore that character and if there is 1 we will include it so we will get every combination
// and one more thing 2^n is 1<<n 
//   so if 3 elements then we want less than 1000 because < 1000 will be 000-111 by this we can create all combination 
  // so 2^n will have n+1 bit and <2^n will have n bits
*//code
  void getSubsequences(string str) {
  vector<string> ans;
  int n = str.length();

  for(int num = 0; num < (1<<n); num++) {
     string temp = "";
     //we will create subsequence string in this temp string
     for(int i=0; i<n; i++) {//this loop is to tell which bit to include and which one not to
          char ch = str[i];
       //here u might get confused by indexing the str is accessed from left to right and the num & (1 << i) checked from right to left
       //so if bit has 001 we consider in abc to add only a , if bit has 011 we consider ab in abc either way it will make all combination
          if(num & (1 << i)) {//geting i'th bit it will return 0 or 1 based on  the i'th bit 
            //non-zero value k liye , include current character
            temp.push_back(ch);
          }
     }

     if(temp.length() >= 0) {
      //store in ans
      ans.push_back(temp);
     }

  }
  sort(ans.begin(), ans.end());
  cout << "Count of subsequences " << ans.size() << endl;
  cout << "printing the subsequences" << endl;
  for(auto i: ans) {
    cout << i << endl;
  }

}
