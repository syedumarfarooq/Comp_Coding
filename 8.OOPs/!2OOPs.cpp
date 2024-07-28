*//Const keyword ***************************************************************************************************************************************************************************
// Const keyword
//   -cannot be changed
    //Initialization
    const int x=5;
    cout<<x;
  // lvalue- are the value having memory location eg:int x
  // rvalue- are the value not having memory location eg:const int x=5,int &x=b;
*****Const with pointers****
1.CONST data,NON-CONST pointer
  const int *c=new int(2); or  int const *c =new int(2);// both are same pointer and has address of value 2
  const int *a=new int;//data/content  of pointer is constant but the pointer can be reassigned =>CONST data,NON-CONST pointer
  *a=2;
  cout<<*a;//2
  //*a=20;//error as deference of a is accessing the data and that cannot be changed
  int b=5;
  a=&b;//pointer itself can be reassigned
  cout<<*a;//5//this will run fine
2.CONST pointer ,NON-CONST data
  int *const a=new int(2);
  cout<<*a;//2
  *a =20;
  cout<<*a;//20
  int b=50;
  a=&b;//error
3.CONST data,CONST pointer
  const int *const a=new int(2);
  cout<<*a;
  *a=5;//error
  int b=5;
  a=&b;//error
