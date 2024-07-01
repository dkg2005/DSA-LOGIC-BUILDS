#include<iostream>
using namespace std;
  
  class node{
    public:
    int data;
    node* next;

    //here i take the data of my linkedlist from constructor
    node(int data){
        this->data = data ;
        this->next = NULL;
    }
    //destructor
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
  void insertNode(node* &tail,int element,int d){
      //if linkedlist is empty
        if(tail == NULL){
          node* Newnode =new node(d);
          tail = Newnode;
          Newnode->next = Newnode;
        }  
        else{
          //asuming linked list is not empty
          node* curr = tail;
          while(curr->next != tail ){
              if(curr->data != element){
                break;
          }
              curr = curr->next;
              }
          //now curr points to the linked list at which element is present
          node* temp = new node(d) ;
          temp->next = curr->next;
          curr->next= temp;
          if (temp->data == element) {
            tail = temp;
           }
        }
  }

  void print(node*tail){
       
       if(tail == NULL) {
        cout<<"list is empty ,please check again"<<endl;
        return;
       }

       node*temp = tail;

       do{

        cout<<tail->data<<" ";
        tail = tail->next;

       } 
        while(tail != temp);
        cout<<endl;
    
  }

 void deletenode(node*& tail, int value) {
    // If the list is empty
    if (tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    }
  
    node* prev = tail;
    node* curr = prev->next; 

    // Search for the node to be deleted
    while (curr->data != value && curr != tail) {
        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is found
    if (curr->data == value) {
        // If there's only one node in the list
        if (curr == tail && curr->next == curr) {
            tail = NULL;
        }
        // If the node to be deleted is the tail
        else if (curr == tail) {
            prev->next = curr->next;
            tail = prev; // Update the tail
        } 
        // For all other nodes
        else {
            prev->next = curr->next;
        }
        curr->next = NULL; // Isolate the node
        delete curr; // Free the memory
        } 
        else {
          cout << "Node with value " << value << " not found in the list" << endl;
        }
}

int main(){
      node* tail = NULL;
      
      insertNode(tail,5,3);
      print(tail);

       insertNode(tail,3,5);
        print(tail);

        insertNode(tail,5,7);
        print(tail);

        insertNode(tail,7,9);
        print(tail);

        insertNode(tail,5,6);
        print(tail);

        deletenode(tail,3);
         print(tail);

    // NOW THIS IS THE PERFECT CODE FOR CIRCULAR LINKED LIST
    return 0;
}