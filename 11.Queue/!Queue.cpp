*// Queue STL******
    #include<queue>
    int main(){
      queue<int> q;
      q.push(10);
      q.push(20);
      cout<<q.size();
      q.pop();//=>10
      if(q.empty()){
        cout<<"queue is empty";
      }else{
        cout<<"queue not empty":
      }
      cout<<"queue front element"<<q.front();
    }
*//Queue without stl******
    class Queue{
      public:
      int *arr;//we have used vector u can use ll also
      int size;
      int front;
      int rear;
      Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
      }
      void push(int data){
        if(rear==size){
          cout<<"Q is full"<<endl;
        }else{
          arr[rear]=data;
          rear++;
        }  
      }
      void pop(){
        if(front==rear){
          cout<<"q is empty"<<endl;
          
        }else{
          arr[front]=-1;
          front++;//after incrementing front then if it equal to rear then it means the q is empty so we are reintiallising the q
          if(front==rear){
            front=0;
            rear=0;
          }
        }
      }
      int getFront(){
        if(front==rear){
          cout<<"Q is empty"<<endl;
          return -1;
        }else{
          return arr[front];
        }
      }
      bool isEmpty(){
        if(front==rear){
          return true;
        }else{
          return false;
        }
      }
      int getSize(){
        return rear-front;
      }
    };
    int main(){
      Queue q(10);
      q.push(10);
      q.push(20);
    }
*//Circular Queue********
    class CirQueue{
      public:
      int size;
      int *arr;
      int front;
      int rear;
      CirQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
      }
      void push(int data){
        
        if(front==0&&rear==size-1||rear==front-1){//or if(rear==(front-1)%(size-1)){
          cout<<"Q is full";                      //       cout<<"Q is full";
      }                                           //    }
        else if(front==-1){
          front=rear=0;
          arr[rear]=data;
        }else if(rear==size-1&&front!=0){
          rear=0;
          arr[rear]=data;
        }else{
          rear++;
          arr[rear]=data;
        }
        void pop(){
          if(front==-1){
            cout<<"Q is empty";
          }
          else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
          }else if(front==size-1){
            front=0;
          }else{
            front++;
          }
        }
    };
*//Doubly Ended Queue*********
    class Deque{
      public:
      int *arr;
      int size;
      int front;
      int rear;
      Deque(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
      }
      void pushRear(int data){
        if(front==0&&rear==size-1||rear==front-1){//or if(rear==(front-1)%(size-1)){
          cout<<"Q is full";                      //       cout<<"Q is full";
      }                                           //    }
            else if(front==-1){
              front=rear=0;
              arr[rear]=data;
            }else if(rear==size-1&&front!=0){
              rear=0;
              arr[rear]=data;
            }else{
              rear++;
              arr[rear]=data;
            }
      }
      void pushFront(int data){
       if(front==0&&rear==size-1||rear==front-1){//or if(rear==(front-1)%(size-1)){
          cout<<"Q is full";                      //       cout<<"Q is full";
      }                                           //    }
            else if(front==-1){
              front=rear=0;
              arr[rear]=data;
            }else if(front==0&&rear!=size-1){
              front=size-1;
              arr[front]=data;
            }else{
              front--;
              arr[front]=data;
            }
      }
      void popFront(){
        if(front==-1){
                cout<<"Q is empty";
              }
              else if(front==rear){
                arr[front]=-1;
                front=-1;
                rear=-1;
              }else if(front==size-1){
                front=0;
              }else{
                front++;
              }
      }
      void popRear(){
        if(front==-1){
                cout<<"Q is empty";
              }
              else if(front==rear){
                arr[front]=-1;
                front=-1;
                rear=-1;
              }else if(rear==0){
                rear=size-1;
              }else{
                rear--;
              }
    }
    };
*//Deque STL******
        #include<deque>
        int main(){
            deque<int> dq;
            dq.push_front(5);
            dq.push_front(10);
            dq.push_back(20);
            dq.push_back(30);
            cout<<dq.size();
            dq.pop_front();
            dq.pop_back();
            cout<<dq.front();//=>5
            cout<<dq.back();//=>20
            if(dq.empty()){
                cout<<"deque not empty";
            }
            
            return 0;
        }
