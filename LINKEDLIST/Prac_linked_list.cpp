#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
 
 void Insert_at_head(node* &head, node* &tail, int data){
    node* temp = new node(data);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void Insert_at_tail(node* &head, node* &tail, int data){
    node* temp = new node(data);
    if (tail == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void print(node* &head){
    node *temp = head;
    while( temp != NULL ){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
  
void Insert_at_position(node* &head, node* &tail, int data ,int position){
    //if inser at head
    if(position == 1){
        Insert_at_head(head, tail, data);
        return;
    }

    node*temp = head;
    int cnt = 1;
    while(cnt < position-1 && temp != NULL){
        temp =temp->next;
        cnt++;
    }
    
    //if insert at tail
    if(temp == NULL){
        Insert_at_tail(head, tail,data);
        return;
    }

    //creating a node to insert
    node*nodetoinsert = new node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert; 

    //update tail if increasing at the end
    if(nodetoinsert->next == NULL) {
        tail = nodetoinsert;
    } 
}

int main(){
  node* head = NULL;
  node* tail = NULL;
    Insert_at_head(head, tail, 10); 
     print(head);
     cout<<"\n";
    Insert_at_head(head, tail, 5); 
     print(head);
      cout<<"\n";
    Insert_at_tail(head, tail, 15);
      print(head);
      cout<<"\n";
      Insert_at_position(head,tail, 7, 2);
  return 0;
}