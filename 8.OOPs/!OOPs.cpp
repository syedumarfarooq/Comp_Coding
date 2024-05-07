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
    public:
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
    Animal(Animal& obj){//by default it is pass by value so when ever copy consturctor is called and it is not send by pass by reference 
        //it keeps on making copy of object and goes inside infinte loop
        this->age=obj.age;
    }
    int main(){
        Animal b=a; or Animal b(a);
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
