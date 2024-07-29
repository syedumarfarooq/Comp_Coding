*//Const keyword ***************************************************************************************************************************************************************************
// Const keyword
//   -cannot be changed
    //Initialization
    const int x=5;
    cout<<x;
  // lvalue- are the value having memory location eg:int x
  // rvalue- are the value not having memory location eg:const int x=5,int &x=b;
*//****Const with pointers****
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
*//****const and function*****
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
*//*MUTABLE********
class abc{
        mutable int x;
        int *y;
        public:
        abc(){
            x=0;
            y=new int(0);
        }
        int getx() const//const will not allow to change any of the member variable but can be overrided if used  mutable
        {
            x=5//no error as using mutable
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
*//*INTIALISATION LIST**********
new way to write constructor(ctor)
//we use this because in old way if any data member is constant they cannot be reintialized inside the constructor but using the new 
//way we can reintialize 
 class abc{
        int x;
        int *y;
        const int z;
        public:
        // abc(int xx,int uy){
        //     x=xx;
        //     y=new int(yy);
        // }
        abc(int _x,int _y,int _z=0):x(_x),y(new int(_y)),z(_z){//abc(1,2,3)=>1,20,3
            *y=*y*10;
            //z=10;//error this cannot be reintialized again 
        }
}
*//*MACROS********
// it is evalutaed by preprocessor before compiling (what it does it replaces the value wherever there are used inside the code before compiling)
    #define PI 3.14
    #define MAXX(x,y) (x>y?x:y)
*//*Shallow and deep copy************
   // Shallow Copy: Copies the reference to the objects. Both the original and the copied objects share the same memory locations.
   // Deep Copy: Copies the actual objects. The original and the copied objects do not share the same memory locations,
    //so changes to one do not affect the other.

    class abc{
    public:
        int x;
        int *y;
        abc(int _x,int _y):x(_x),y(new int(_y))){}
         //default dumb copy constructor: it does show copy
            // abc(const abc &obj){
            //     x=obj.x;
            //     y=obj.y;
            // }
        //deep copy constructor
        //it creates a deep copy where it will variable stores seperately specifically for this so not sharing like shallow copy
            // abc(const abc &obj){
            //     x=obj.x;
            //     y=new int(*obj.y);//copy the value of y and putting it into another address in heap
            // }
        void print() const{
            cout<<"x"<<x<<"y ptr"<<y<<"*y"<<*y;
        }
        //destructor
        ~abc(){
            delete y;
        }
    }
    int main(){
        abc a(1,2);
        // a.print();//y=2
        delete a;//this will call the destructor
        abc b=a;//while coping the default constructor  is called which is created by c++ or os
        //default dumb constructor: it does show copy
            // abc(const abc &obj){
            //     x=obj.x;
            //     y=obj.y;
            // }
        b.print();//y=2//after destructor this will print empty value of y as a deleted the content inside
        //but then after 
        
        // both b and a will point to the same y(address same) so they become interdependent if  y is freed from object a then object b 
        //cannot access it
        // *b.y=20;
        // b.print();//y=20 
        //so whenever y of b is changed it changes y of a because default dumb constructor does shallow copy
        //to prevent this we use deep copy
        // a.print();//y=20 after deep copy y remains 2
        return 0;//objs goes out of scope here and destructor is called automatically
        //but this will show error as we are double freeing the same obj when using default copying constructor i.e shallow copy
    }

*//Global and local variable****************
    // If there are both global and local variable inside a function local variable will be given preference
    // to access global variable if there is local varible present inside the function we use ::x
    #include<iostream>
    using namespace std;
    int x=5;
    int main(){
        cout<<::x;//5
        ::x=15;
        int x=10;
        cout<<x;//10
        cout<<::x;//15
        return 0;
    }
    // global variable
    // -writen outside a function
    // -accessible by all function
    // local variable
    // -written inside a function
    // -accessible inside that scope function
*//Static keyword**********
    *//static data members:that variable is going to share memory with all the class instances
    //default behaviour
    #include <iostream>
    class abc{
        public:
        int x,y;
        print(){
            cout<<this->x<<this->y;
        }
    }
    int main()
    {
        abc a={1,2};
        abc b={4,5};
        a.print();//1,2
        b.print();//1,2
        return 0;
    }
    //after using static
    #include <iostream>
    class abc{
        public:
        static int x,y;
        void print(){
            cout<<x<<y;
        }
    }
    int abc::x;//static members are intialized outside
    int abc::y;
    int main()
    {    
        abc a;
        a.x=1;
        a.y=2;
        a.print();//1 2
        abc b;
        b.x=10;
        b.y=20;
        a.print();//10 20
        b.print();//10 20
        //by using static all the instances ie a,b we use the same x and y
        //abc classes all instances will share the one copy of variable
        return 0;
    }
    *// static member function:there is no instance(this) of that class being passed into that method and that method will be same for all 
        // instances
 #include <iostream>
    class abc{
        public:
        static int x,y;
        static void print(){//this print function will be same for all the instances //if x and y will not be static it will not print
            //as the variable used inside the function are passed by the instances
            cout<<x<<y;
        }
    }
    int abc::x;//static members are intialized outside
    int abc::y;
    int main()
    {    
        abc a;
        a.x=1;//or abc::x=1;
        a.y=2;
        a.print();//1 2
        abc b;
        b.x=10;
        b.y=20;
        a.print();//10 20
        b.print();//10 20
        //by using static all the instances ie a,b we use the same x and y
        //abc classes all instances will share the one copy of variable
        return 0;
    }
