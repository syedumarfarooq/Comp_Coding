*//Abstraction************************************************************************
    // delivering only essential information to the outer world while masking the outer detail
    // it is design or programming method that separtes the interface from implementation
    *//Abstract class
    // An abstract class is like a blueprint for other classes. You can't create objects from it
        // directly. Instead, it is used to create other classes that inherit from it.
        *//bird.h
        #if !defined(BIRD_H)
        #define BIRD_H
        #include <iostream>
        class Bird{//Abstract class
            virtual void eat()=0;
            //A pure virtual function is a function that doesn't have any code in the base (abstract) 
    // class. It’s like a placeholder that says, "Every class that inherits from me must provide its own version of this function."
            virtual void fly()=0;
            };
        class sparrow:public Bird{
            private:
                void eat(){
                    std::cout<<"sparrow eating";
                }
                void fly(){
                    std::cout<<"sparrow flying";
                }
        };
        class eagle:public Bird{
                private:
                    void eat(){
                        std::cout<<"sparrow eating";
                    }
                    void fly(){
                        std::cout<<"sparrow flying";
                    }
            };
        #endif
        *//main.cpp
        #include <iostream>
        #include "bird.h"
        using namespace std;
        void birddoesSomething(Bird *&bird){
            bird->eat();
            bird->fly();
        }
        int main(){
            Bird *bird=new sparrow();
            //Bird *bird=new Bird();//error
            birddoesSomething(bird);
            return 0;
        }
*//Inline function************************************************************************
    // - The code for an inline function is inserted directly into the code of the calling function by compiler while 
    // compiling, which can result in faster execution and less overhead compared to regulaufunction calls.
    // -Instead of calling function the statements of functions are pasted in calling function.
    // -Used with small sized functions(the inline funciton should be small)/So that executables are small 
    // (handled automatically by compiler optimisation levels).
    inline void printnum(int num){//works good for small functions and can be used where the function is called many times
        cout<<num;
    }
    int main(){
        printnum(10);
    }
    // now current compiler will decide to add inline if the function is small and will ignore inline if the funciton is large
*//Friend keyword************************************************************************
    // 1. friend is a keyword in C++ that is used to share the information of a class that was previously hidden.
    // it is used to access private members of a class
    // 2. For example, the private members of a class are hidden from every other class and cannot be modified except
    // through getters or setters. Similarly, the protected members are hidden from all classes other than its children classes.
    #include <iostream>
    using namespace std;
    class A{
    private: 
    int x;
    public:
        A(int _val):x(_val){};
        int getX() const {return x;}
        void setX(int _val){
            x=_val;
        }
        friend class B;//b is friend of a and can access private members of a
        friend void print(const A &);//function is a friend

    ｝;
    class B{
    public:
        void print (const &a){
            cout<<a.x();//without making friend u cannot access x
        }
    };
    void print(const A &a){
        cout<<a.x;;//without making friend u cannot access x
    }
    int main (){ 
        A a (5) ;
        B b;
        b. print (a);
        return 0;
    }
*//Can Constructor be made private**********************
    //Yes constructor can be made private
    
    class Box{
        int width;
        Box(int _w):width(_w){};
        public:
            int getWidth() const{
                return width;
            }
            void setWidth(int _val){
                width=_val;
            }
            friend class BoxFactory;
    };
    class BoxFactory{
        int count;
        public:
            Box getABox(int _w){
                return Box(_w);//this also cannot be accessed if the boxfactory is not made friend
            }
    };
    int main(){
        // Box b(5);//this will show error as the constructor is private it cannot be initialized
        //this can be used if u do not want anyone to directly cannot box object 
        // cout<<b.getWidth();
        BoxFactory bfact;
        Box b=bfact.getABox(10);
        cout<<b.getWidth();
        return 0;
    }
*//virtual in c++********************
    //it is a way to achieve runtime polymorphism
    //if virtual is used in the parent function the compiler will create static arrays table(i.e virtual table) for the parent and will        
    //point its methods(functions) to its parent method( assume the parent and child class has same functions ) and then the child class will
    //also create static arrays table
    //which point child or parent function based on the use of virtual if the parent function used  virtual then the child function(has        
    //same name) as the parent function will point the child function from inside the child but the not virtual function used will point the            
    //parent function itself
    
class Bird{
    virtual void fly(){
        cout<<"bird flying";
    }
    void sleep(){
        cout<<"bird sleeping";
    }
}
class Bird:public sparrow{
    void fly{
        cout<<"sparrow flying";
    }//bcz of virtual in parent class this will point the parent function fly i.e sparrow flying;
    void sleep{}
}
int main(){
    Bird *b=new sparrow();
    b.fly();//sparrow flying;
    b.sleep();//bird sleeping;
}
    *//vptr**************
        1.Vptr( a hidden member pointer) is added by complier to classes with virtual and its derived class
        2. Depending upon the object type VPtr is bonded to a VTable.
            eg. Bird *b=new sparrow(); after this the vptr will point to sparrow virtual table
                //for b.fly() b's vptr will point to the child (sparrow) virtual table as virtual is used
    *//virtual constructor**************
        // no a virtual constructor cannot be created
    *//virtual destructor**************
        // yes it can be created
            class Base{
                    Base(){
                    cout<<"base consturctor";
                    }
                virtual ~Base(){//virtual destructor
                cout<<"base destructor";
            }
            class Derived{
                    Derived(){
                    cout<<"derived consturctor";
                    }
                ~Derived(){
                cout<<"derived destructor";
            }
            int main(){
                Base *b=new Derived();
                delete b;//derived destructor
                         //base destructor
                //if u use virual in base destructor both the destructor with called or else only the base destructor is 
                        //is called
                return 0;
            }
*//Memory layout of a program********************
