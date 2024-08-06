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
        friend class B;
        friend void print(const A &);
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
