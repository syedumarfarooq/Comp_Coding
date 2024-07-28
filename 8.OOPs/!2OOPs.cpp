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
*****const and function*****
class abc{
    int x;
    int *y;
    public:
    abc(){
        x=0;
        y=new int(0);
    }
    int getx() const//const will not allow to change any of the member variable
    {
        x=5//error
        return x;
    }
    int setx(int val){
        x=val;
        
    }
    nt gety() const//const will not allow to change any of the member variable
    {   y=&f;//error
        return *y;
    }
    int sety(int val){
        *y=val;
        
    }
}
void printABC(const abc &a){//as we are using const object( passed by reference then all the functions/method shoud be const i.e a.getx() and 
//a.gety() should be const or else shows error
//so u can call only const function inside this function
cout<<a.getx()<<a.gety();//
}
int main()
{
    abc();

    return 0;
}
