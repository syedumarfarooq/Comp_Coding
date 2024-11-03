*// Hashmap**
// it is a data structure which stores data in key,value pair
// ordered map store ,search and deletes in O(logn)
*// unordered map stores ,searches and deletes in O(1)***
*//HASHMAP STL****
#include<unordered_map>
int main(){
  //creation
  unordered_map<string,int> m;
  //insertion
  pair<string,int>p=make_pair("umar",1);
  // m.insert(p);
  //    //or
  // pair<string,int>p2("syed",2);
  // m.insert(p2);
     //or
  m["farooq"]=10;
  //access
  // cout<<m.at("farooq")<<endl;//=>n 10
  // cout<<m.at("Syed")<<endl;//=><empty or error as S is capital and ther is no entry>
  cout<<m["umar"]<<endl;
  //serach
  cout<<m.count("umar")<<endl;//0 or 1 depending on the exsistance of the key
  if(m.find("umar")!=m.end()){//find function returns iterator and if it is pointing at end
    //means not found;
    cout<<"found"<<endl;
  }else{
    cout<<"NOT FOUND"<<endl;
  }
  //automatically creates entry
  cout<<m.size()<<endl;//=>3
  cout<<m["hitler"]<<endl;//=>0 as there is no entry
  cout<<m.size()<<endl;//=>4 as this creates an entry of hilter and intialize it will ziero
  //printint
  cout<<"Printing all entries:"<<endl;
  for(auto i:m){
    cout<<i.first<<"->"<<i.second<<endl;
  }
}
*//Implementation***
// ordered map is based on BST so thats y logn
// unordered map is array based implementation uses hash function which takes in input value and it gives which indexed the value should be placed
// Hash function is made of hash code and compression function
// hash code is responsible for conversion of key to numeric value  which may be or may not be in range
// compression functions works it to bring the numeric value inside the range (i.e it applies mod to the numeric value to bring it in range eg:the range is 0 to 4 if the numeric value 
  // is 22 then it will apply modulos and make it 2
*//Collision
// if 2 different values passed into the hash function and it gives same numerica value this is called collision
// there is always collision it cannot be null but it should minimised

// A good map is where minimal collison happens and it is because of strong hash function
*//Collision handling 
// there is always a collision irrective of how good a map it is but how will u save from it
*//Open Hashing is one of the method for collision handling*
*//Open Hashing*
// so when there is a value tring to be place on a index but there is already a value so then u save both values in linked list by creating  a linked list adding the values to it and 
  // then storing the head of it to the main array
 *//Closed Addressing is another method for collision handling*
// so when there is a value trying to be placed on a index but there is already a value so then u find the next free space to insert it
// Finding Free space
*//Linear Probing*
// one method is u go on checking next index one after another to find a free one this method of iteraively checking free space on every index is also called linear probing
*//Quadratic Probing*
// another method in search of free space u go next i^2 place n check eg:next current+1^2 or current+2^2 or current+3^2 i.e 1,4,9th places after the current place and so on 
// Cubic Probing
// same as Quadratic probing but next i^3 place
*//A GOOD HASH FUNCTION*
//   a good hash function should follow the below criteria for minimal collision
// if a array consists 
// n no of elements
// b no of free boxes then
// n/b(load factor)<0.7 i.e no of elements < no of gree boxes
*//Time complexity
// 1)we have been told that when value (eg:umar) is passed into the hash function it iteraties through every char to create numeric value
// so this means if k is the length of input value then time complexity is O(k) then we have been told it is O(1)
// as the length n(array length) >>> far more greater than length k  so we are assuming O(k) is equal to O(1) approximation
// 2)assume there are multiple values trying to be inserted at the same place then it creates linked list so atleast then the time complexity is O(N) as trying to access
// the linked list but we have created the hash function so strong that load factor is <0.7 i.e(n/b) this wont let it happen i.e it wont let many values pointing to the same index
// as it is alloted to free spaces so this case wont excist 
