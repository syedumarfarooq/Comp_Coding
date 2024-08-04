*//Abstraction************
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
