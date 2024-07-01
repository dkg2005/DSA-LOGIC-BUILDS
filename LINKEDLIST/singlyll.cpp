#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    //here i take the data of my linkedlist from constructor
    node(int data){
        this->data = data ;
        this->next = NULL;
    }
     ~node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void Insert_at_head(node* &head, int data){
    node*temp = new node(data);
    temp->next =head; 
    head = temp;
}

void Insert_at_tail(node* &tail ,int data){
     node*temp = new node(data);
     tail->next =temp;
     tail = temp;
} 

void Insert_at_poistion(node* &tail,node* &head ,int data ,int poistion){
    //if inser at head
    if(poistion == 1){
        Insert_at_head(head,data);
        return;
    }

    node*temp = head;
    int cnt = 1;
    while(cnt < poistion-1){
        temp =temp->next;
        cnt++;
    }
    
    //if insert at tail
    if(temp->next == NULL){
        Insert_at_tail(tail,data);
        return;
    }

    //creating a node to insert
    node*nodetoinsert = new node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;  
}

  //deletion 
  void deleteNode(int poistion ,node* &head,node* &tail){
    
    //If linked list is already empty
    if(head == NULL){
        cout<<" LINKED LIST IS EMPTY";
        return;
    }

    //deleting first node
    if(poistion == 1){
        node *temp = head;
        head = head->next;
        //memory free
        temp->next =NULL;
        delete temp;
    }

    else{

        //deleting other than first node
        node* curr  = head;
        node*prev = NULL;
        int cnt = 1;

        while(cnt<poistion){
            prev = curr;
            curr = curr->next ;
            cnt++;
        }
        // if deleting last node
        if(curr->next == NULL){
          tail = prev;
           // tail->next = NULL;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
  }
void print(node* &head){
    node *temp = head;
    while( temp != NULL ){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    //created  a new node node1
    node * node1 = new node(10);
      // cout<<node1->data<<endl;
      //  cout<<node1->next<<endl;
     
    //head pointed to node1
      node* head = node1;
       //   Insert_at_head(head, 9);
          Insert_at_head(head, 8);
          Insert_at_head(head, 6);
         // print(head);

    
    node *tail = node1;
           Insert_at_tail(tail, 11);
           Insert_at_tail(tail, 12);
   // print(head);


         Insert_at_poistion(tail,head,7,2);    
         Insert_at_poistion(tail,head,9,4);             
        print(head);
         cout<<endl;
         cout<<"head : "<<head->data<<endl;
         cout<<"tail : "<<tail->data<<endl;


          deleteNode(3,head,tail);             
          print(head);
           cout<<endl;
         cout<<"head : "<<head->data<<endl;
         cout<<"tail : "<<tail->data<<endl;

          deleteNode(6,head,tail);             
          print(head);
           cout<<endl;
         cout<<"head : "<<head->data<<endl;
         cout<<"tail : "<<tail->data<<endl;
    return 0;
}
