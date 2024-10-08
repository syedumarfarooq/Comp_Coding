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
  return 0;
}
