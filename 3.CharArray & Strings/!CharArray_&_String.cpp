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
    // Question 3
    // # Check Palindrome
    bool checkPalindrome(char name[]){
       int i=0;
      int n=getLength(name);
      int j=n-1;
      while(i<=j){
        if(name[i]!=name[j]){
          return false;
        }
        else{
          i++;
          j--:
            }
      }
      return true;
    }
//String
    #include<string>
    string str;
    cin>>str; or getline(cin,str);
    cout<<stf;

    str.length();

    str.empty();

    str.push_back();

    str.pop_back();

    str.substr(0,6);

    if(str1.compare(str2)==0)//=>0(strings are exactly same) or 1 determines if the two string are same or not if output <0 then str2 have high ascii value compared to str1 if >0 then str1 has high ascii value compared str2 and if both the first character are same then it checks for next character
      
    str1.find(str2);//if findes the index in str1 where str2 substring is present that is the starting index
    if(str1.find(str2) == std::string::npos){
      cout<<"NOT FOUND";
    }

    str.replace(starting_index,ending_index,str2);//so str starting to ending index is replaced with str2

    str.erase(starting_index,no_of_characters_to_be_erased);

//Connect class
// custom comparator for sort
bool cmp(char first,char second){
    //so basically it depends on the function in which order the elements will be placed if the function cmp(a,b) return true then the 
     // a will be placed before b and if false then b will be placed before
    
    return first<second//for increasing// here if first is less than second the result is true so first will be placed before second
        //as cmp(first,second)
    return first>second//for decreasing
}
int main(){
string s="umar";
sort(s.begin(),s.end(),cmp);
cout<<s<<endl;
return 0;
}


