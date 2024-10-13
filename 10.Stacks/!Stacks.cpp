*// Stack using stl****
    #include<iostream>
    #include<stack>
    using namespace std;
    int main(){
      //creation
      stack<int> st;
      //insertion
      st.push(10);
      st.push(20);
      //remove
      st.pop();
      cout<<st.top();
      cout<<st.size();
      if(st.empty()){
        cout<<"empty";
      }
      //printing all elements;
      while(!st.empty()){
        cout<<st.top();
        st.pop();
      }
      
    }
*//Stack without STL********
        class Stack{
          public:
          int* arr;
          int top;
          int size;
          Stack(int size){
            arr=new int[size];
            this->size=size;
            top=-1;
          }
            void push(int data){
                if(size-top>1){
                    //space available
                    //insert
                    top++;
                    arr[top]=data;
                }else{
                    cout<<"Stack Overflow";
                }
            }
            void pop{
                if(top==-1){
                    cout<<"Stack Underflow";
                }else{
                    top--;
                }
            }
            int getTop(){
                if(top==-1){
                    cout<<"Stack is empty";
                }else{
                    return arr[top];
                }
            }
            int getSize(){
                return top+1;
            }
            bool isEmpty(){
                if(top==-1){
                    return true;
                }else{
                    return false;
                }
            }
        }
        int main(){
            Stack s(10);
            s.push(10);
            s.push(20);
            s.push(30);
            while(!s.isEmpty()){
                cout<<s.getTop();
                s.pop();
            }
        }
*//Two Stacks in One array ************
        #include <iostream>
        using namespace std;
        
        class Stack{
                public:
                int *arr;
                int size;
                int top1;
                int top2;
        
                Stack(int size) {
                        arr = new int[size];
                        this->size = size;
                        top1 = -1;
                        top2 = size;
                }
        
                //functions
                void push1(int data) {
                        if(top2 - top1 == 1) {
                                //space not available
                                cout << "OVERFLOW int stack 1" << endl;
                        }
                        else {
                                //space available
                                top1++;
                                arr[top1] = data;
                        }
                }
        
                void pop1() {
                        if(top1 == -1) {
                                //stack empty
                                cout << "UNDERFLOW in stack 1" << endl;
                        }
                        else {
                                //stack not empty
                                top1--;
                        }
        
                }
        
                void push2(int data) {
                        if(top2 - top1 == 1) {
                                //space not available
                                cout << "OVERFLOW in stack 2" << endl;
                        }
                        else {
                                top2--;
                                arr[top2] = data;
                        }
                }
        
                void pop2() {
                        if(top2 == size) {
                                //stack 2 is empty
                                cout << "UNDERFLOW in stack 2" << endl;
                        }
                        else {
                                //stack 2 is not empty
                                top2++;
                        }      
                }
        
                
        };
        
        int main() {
                Stack s(10);
        
                s.push1(10);
                
                s.push1(20);
                
                s.push1(30);
                
                
        
                s.push2(100);
                
                s.push2(110);
                s.push2(120);
                s.push2(130);
                s.push2(140);
                
                
                s.pop1();
                s.pop1();
        
        s.pop1();
        
        s.pop1();
        
               
          return 0;
        }
