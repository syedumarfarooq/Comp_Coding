*//  Linked Lists*******************
  *//Node creation*********
  // Singly Linked list
    class Node{
      public:
      int data;
      Node *next;
       Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }
    } 
 //Printing linked list
    void print(Node* head) {
   
           Node* temp = head;
           while(temp != NULL) {
                   cout << temp->data << " ";
                   temp = temp->next;
           }
   }
   int main(){
    //not the right way to create linked list just for understanding
     Node* first=new Node(10);
     Node* second=new Node(10);

     Node* third=new Node(10);
     Node* fourth=new Node(10);
     Node* fifth=new Node(10);
     
     first->next=second;
     second->next=third;
     third->next=fourth;
     fourth->next=fifth;
     print(first);
   }
  
  
    // Types of linked list
     // 1.Singly ll
     // 2.Circular ll
     // 3.Doubly ll
     // 4.Circular doubly ll

