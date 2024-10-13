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
}
