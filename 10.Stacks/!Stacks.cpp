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
