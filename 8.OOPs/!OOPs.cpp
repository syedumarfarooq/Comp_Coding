*//Class 1 ***************************************************************************************************************************************************************************
// OOPs
//   It is a programming technique which revolves around object
// Object
//   1)state/properties
//   2)behaviour/method
// Class
//   using classes we can create user defined datatyes
// Access Modifiers-they define the scope of access
//   1)public-this can be accessed inside and outside class.
//   2)private-by default properties method are marked private that means can be accessed only inside class.
//   3)protected
#include <iostream>
using namespace std;
class Animal{
    public://anything below it is public
    //state or properties
    int age;        //data members
    string name;    //data members
    //behavior 
    void eat(){     //member functions
        cout<<"eating"<<endl;
    }
    void sleep(){   //memger functions
        cout<<"sleeping"<<endl;
    }
};
int main()
{
    Animal ramesh;
    ramesh.age=12;
    ramesh.name="lion";
    cout<<ramesh.age<<endl;
    cout<<ramesh.name<<endl;
    ramesh.eat();
    ramesh.sleep();
    return 0;
}
// GETTER AND SETTER
//   when u want to access private member outside class you use getter and setter
    int getWeigth(){
        return weight;
    }
    void setWeigth(int w){
        weight=w;
    }
    //to set 
    ramesh.setWeight(101);
    cout<<ramesh.getWeight();
// NEW
//  using new keyword to allocate in heap memory location
//  eg:new int;=>return the address of memory location
// int* a=new int;//created a new int which is present in heap memory
// int* ptr=new int[5];//in this a array of 5 size is allocated in heap memory and its address is stored in pointer ptr which is in stack memory
// NOTE://in stack memory can be cleaned automatically but in heap it is not cleaned automatically
//Dynamic Memory
    Animal* suresh=new Animal;
    (*suresh).age=15;  or suresh->age=15;
    (*suresh).name="billi"; or suresh->name="billi";
    suresh->eat();
    suresh->sleep():
//This
    it is a pointer to current object
    this->weight=weight;//this means current object ka weight
//Constructor- it initialized object
    //default constructor
    class Animal{
    public:
    //state or properties
    int age;        //data members
    string name;    //data members
    //cunstructor
    Animal(){
        this->age=0;//initializing the properties
        this->name="";
        //by default constructor runns whenever object is created
    }
    //behavior 
    void eat(){     //member functions
        cout<<"eating"<<endl;
    }
    void sleep(){   //memger functions
        cout<<"sleeping"<<endl;
    }
};
    //parameterised constructor
    Animal(int age,string name){
        this->age=age;
        this->name=name;
        //by default constructor runns whenever object is created
    }
    //copy consturctor
    Animal(Animal& obj){//by default it is pass by value so when ever copy consturctor is called  we use & and it is  
        //send by pass by reference to prevent from entering into a infinte loop
        //(so in parameter Animal Obj is used
        //so as it makes a copy of obj because sending it pass by value if we dont use '&' and whenever a copy is made, it calls 
        //copy constructor this enters into a infinite loop)
        //it keeps on making copy of object and goes inside infinte loop if it is not passed by reference by using &
        this->age=obj.age;
    }
    //copy object
    int main(){
        Animal b=a; or Animal b(a);//copy constructor is called
    }
//Destructor
    Animal{
        ~Animal(){
        //destructor
        }
    };
    int main(){
        Animal a;
        a.age=5;//this will call destructor automatically at the end of the main function//static memory allocation
        //but in dynamic memory allocation u have to manually do it
        Animal* b=new Animal():
        delete b;
    }
*//Class 2 ***************************************************************************************************************************************************************************
// 4 Pillars of OOPs
//     1)Encapsulation
//     2)Inheritance
//     3)polymorphism
//     4)Abstraction
// Encapsulation-Data hiding
//Inheritance-
    // the child class/sub class inherit the properties from parent class/super class
    #include <iostream>
using namespace std;
class Animal{
    public:
    int age;
    int weight;
    void eat(){
        cout<<"Eating"<<endl;
    }
};
class Dog:public Animal{
    
};
int main()
{
    Dog d1;
    d1.eat();

    return 0;
}
// BASE CLASS KA ACCESS MODIFIER |||| MODE OF INHERITANCE
//     public,public->public
//     public,protected->protected
//     public,private->private
//     protected,public->protected
//     protected,protected->protected
//     protected,private->private
//     private,public->not accessable
//     private,protected->not accessable
//     private,private->not accessable
Types of inheritance
    1.single 
    2.multi-level
    3.multiple//-class C:public A,public C{};
    4.hierarchial
    5.hybrid//-mixture of all types of inheritance
    
    
*//IMP ***************************************************************************************************************************************************************************    
// Multiple
    // Scope Resolution operator
    //Diamond problem question is when there are two same properties in different class eg:chemistry then scope resolution 
    //operator is used to tell compiler that we are specificing which property of the object that is which chemistry from a or b class
    
    #include <iostream>
    using namespace std;
    class A{
        public:
        int chemistry;
        A(){
            chemistry=100;
        }
    };
    class B{
        public:
        int chemistry;
        B(){
            chemistry=111;
        }
    };
    class C:public A,public B{
        
    };
    int main(){
        C obj;
        cout<<obj.B::chemistry;//scope Resolution operator
        return 0;
    }
// POLYMORPHISM-existing in many forms
    1.compile-time polymorphism
    2.run-time polymorphism
//Compile-time polymorphism it is based on
    1.function overloading
    2.operator overloading
//Function Overloading
    #include <iostream>
    using namespace std;
    class Math{
        public:
        int sum(int a,int b){
            return a+b;
        }
        int sum(int a,int b,int c){
            return a+b+c;
        }
        int sum(int a,float b){
            return 100;
        }
    };
    int main(){
        Math obj;
        cout<<obj.sum(1,2.0f);
        return 0;
    }
//Operator Overloading
    #include <iostream>
    using namespace std;
    class Param{
        public:
        int val;
        void operator+(Param& obj2){
            int value1=this->val;
            int value2=obj2.val;
            cout<<(value2-value1)<<endl;
        }
    };
    int main(){
        Param obj1,obj2;
        obj1.val=7;
        obj2.val=2;
        obj1+obj2;
        return 0;
    }
