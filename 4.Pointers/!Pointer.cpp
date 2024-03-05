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
        //1.first a in temporary storage umar is saved
        //2.then it is copied to chr array
        cout<<*c;//=>U
        cout<<c;//=>THIS WILL PRINT UMAR
        cout<<chr;//=>umar
        //it prints out the entire string of that address
        char name[10]="syedUmar";
        char* c=&name[0];
        cout<<name;//=>syedUmar
        cout<<c;//=>syedUmar
        cout<<c+2;//=>edUmar
        cout<<*(name+3);//=>d
        char ch='k';
        char* c=ch;
        cout<<c;//=>this will print k and some garbage values till the null character is found eg:k^a;dfk
        char* ccc="syedumar";//BAD PRACTISE   
        cout<<ccc;//=>syedumar
        //1.first syedumar is stored temporarily and then
        //2.then it is pointed through a pointer
    //FUNCTION AND POINTER
        //whenever a array is passed into a function it is passed by reference that is a pointer is created in the function and it contains the base address of the array so the &arr in main function will have the base address and &arr in the function will have a different address as a new pointer is created
        //eg:
        void solve(int *p){
            *p=*p+10;    //p is a new pointer created with the address of a
        }
        int main(){
            int a=5;
            int *ptr=&a;
            solve(ptr);
            cout<<a;//=>15
        }
//CLASS 3
    //DOUBLE POINTER
        int a=5;
        int* p=&a;//p is a pointer to a and contains address of p
        int** q=&p;//q is a pointer to p and contains address of p
        cout<<*q;//this gives the addess of a as the value at address of p contains address of a
        cout<<**q;//this gives the value of a 
    //FUNCTION AND DOUBLE POINTER
        int main(){
            int x=12;
            int* p=&x;
            int** q=&p;
            cout<<p;//for eg;104
            solve(q);
            cout<<p;//=>108 as it has been changed in the function because of *ptr+=1;
        }
        int solve(int** ptr){
            *ptr=*ptr+1;//&x is changed 
            **ptr=**ptr+1;//this changes the value of x to 13
            
        }
    //REFERENCE VARIABLE
        // same memory location can be accessed through different names
        //it is used in pass by reference concepts
        int a=5;
        int& b=a;//b is a reference variable and pointing to the same memory location of a
        a++;
        cout<<a<<b;//=>6 6
        b++;
        cout<<a<<b;//=>7 7
    //FUNCTIONS AND REFERENCE VARIABLE
        void solve(int &value){
              value++'
        }
        int main(){
            int a=5;
            solve(a);
            cout<<a;//=>6
        }
