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
    cout<<*ptr;//it access the value whose address is stored in ptr
  // why pointers?
    // 1.Dynamic memory allocation
    // 2.Memory management
    // 3.accessing hardware
    // 4.to pass a function into another function we use pointer
//int* ptr;//BAD PRACTISE
  int* ptr=0;//NULL POINTER
  int* ptr=NULL;
  int* ptr=nullptr;

