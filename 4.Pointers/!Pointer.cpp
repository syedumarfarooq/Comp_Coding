// CLASS 1
  int a=5;
  char ch='a';
  cout<<&a;//where & is the address of operator and it is stored in symbol table
//Pointer is a variable that stores address of another variable
//In pointer only address is stored
//using pointer address and value in that address can be accessed
  int* ptr=&a;//ptr is a pointer to a which contain integer data
  char* p=&ch;//p is a pointer to ch which contain char data
//*->it is used to create pointer and dereference operator
  cout<<*ptr;//access the value ptr is pointing to
