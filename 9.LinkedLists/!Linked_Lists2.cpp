*// Doubly Linked List**********
class Node{
  public:
  int data;
  Node* prev;
  Node* next;
  Node(){
    this->data=0;
    this->prev=NULL;
    this->next=NULL;
  }
  Node(int data){
    this->data=data;
    this->prev=NULL;
    this->next=NULL;
  }
}
void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
}
int getLength(Node* head){
  int len=0;
  Node* temp=head;
  while(temp!=NULL){
    temp=temp->next;
    len++;
  }
}
void insertAtHead(Node* &head,Node* &tail,int data){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
    return;
  }
  Node* newNode=new Node(data);
  newNode->next=head;
  head->prev=newNode;
  head=newNode;
}
void insertAtTail(Node* &head,Node* &tail,int data){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
    return;
  }
  Node* newNode=new Node(data);
  newNode->prev=tail;
  tail->next=newNode;
  tail=newNode;
}
void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //LL is not empty
                if(position == 1) {
                        insertAtHead(head,tail, data);
                        return;
                }
                int len = getLength(head);
                if(position > len) {
                        insertAtTail(head, tail, data);
                        return;
                }
                // insertion in middle
                //step1: find prev && curr
                int i = 1;
                Node* prevNode = head;
                while( i < position - 1) {
                        prevNode = prevNode ->next;
                        i++;
                }
                Node* curr = prevNode -> next;

                //step2: create a node
                Node* newNode  = new Node(data);

                //step3:
                 newNode -> prev = prevNode;
                prevNode -> next = newNode;
                newNode ->next = curr;
                curr -> prev = newNode;
                
        }
}

void deleteFromPos(Node* &head, Node* &tail, int position) {
        if(head == NULL) {
                cout << "Linked list is empty";
                return;
        }
        if(head -> next == NULL) {
                //single node
                Node* temp = head;
                head = NULL;
                tail = NULL;
                delete temp;
                return;
        }
        int len = getLength(head);
        if(position > len) {
                cout << "please enter a valid position " << endl;
                return;
        }

        if(position == 1) {
                //want to delete the first node
                Node* temp = head;
                head = head ->next;
                head -> prev = NULL;
                temp ->next = NULL;
                delete temp;
                return;
        }
        
        if(position == len) {
                //delete last node
                Node* temp = tail;
                tail = tail -> prev;
                temp ->prev = NULL;
                tail ->next = NULL;
                delete temp;
                return;
        }

        //delete from middle of linked list

        //step1: find left, curr, right
        int i = 1;
        Node* left = head;
        while( i < position - 1) {
                left = left -> next;
                i++;
        }
        Node* curr = left -> next;
        Node* right = curr -> next;

        //step2:
        left -> next = right;
        //step3:
        right -> prev = left;
        //step4:
        curr -> next = NULL;
        curr ->prev = NULL;
        delete curr;


}

int main(){
  Node* first=new Node(10);
  Node* second=new Node(20);
  Node* third=new Node(30);
  Node* head=first;
  Node* tail=third;
  first->next =second;
  second->prev=first;

  second->next=third;
  third->prev=second;
  print(first);//10 20 30
  cout<<endl;
  insertAtHead(head,tail,101);
  insertAtTail(head,tail,201);
  insertAtPosition(head,tail,2,25);

  return 0;
}
