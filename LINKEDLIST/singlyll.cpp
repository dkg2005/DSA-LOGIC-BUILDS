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
         Insert_at_poistion(tail,head,5,1);             
         Insert_at_poistion(tail,head,19,9);              
         print(head);

         cout<<"head : "<<head->data<<endl;
         cout<<"tail : "<<tail->data<<endl;
    return 0;
}
