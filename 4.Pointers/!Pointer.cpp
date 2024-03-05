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
    //copying ptr
    int* ptr=&a;
    int* secondptr=ptr;
// CLASS 2
    //ARRAY
        int arr[4]={1,2,3,4}
        cout<<arr;//this gives the base address of arr            }
        cout<<&arr;//this also gives the address of  arr          }there address are all same
        cout<<&arr[0]//this gives the address of arr              }
        cout<<*arr;//this gives 1 as output 
        cout<<*(arr+1);//=>2
        cout<<*(arr+i)<<arr[i]<<i[arr];//all are same 
        int* p=arr;
        arr=arr+1;//ERROR arr base address cannot be changed because constant pointer
        p=p+1;//works fine
    //CHAR ARRAY
        //cout implementation is different for char array
        char chr[10]="umar";
        char* c=chr;
        cout<<*c;//=>U
        cout<<c;//=>THIS WILL PRINT UMAR
        //it prints out the entire string of that address


