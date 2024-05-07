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
