// Class I
// CHAR ARRAY
  char name[100];
  cin>>name;
  cin>>name[2];//this takes input of single character
// NOTE:by default at the end of char array an null character is placed "\0" is discribes string termination
  #include <string.h>
  cin.getline(name,50);//it is used to get input of char where there are spaces included for example :name is umar syed it will take in just umar
  // but if you use getline it takes input as umar syed
  // Question 1
  // #To find length of char array
  int getLength(char name[]){
    int length=0,i=0;
    while(name[i]!='\0'){
        length++;
        i++;
    }
  return length;
  }
  //Predefined function 
  #include <string.h>
  strlen(name);
  // Question 2
  // # Reverse a string
  int reverseCharArray(char name[]){
    int i=0;
    int n=getLength(name);
    int j=n-1;
    while(i<j){
      swap(name[i],name[j]);
      i++,j--;
    }

