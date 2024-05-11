
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
      //if linkedlist os empty
        if(tail == NULL){
          node* Newnode =new node(d);
          tail = Newnode;
          Newnode->next = Newnode;
        }  
        else{
          //asuming linked list is not empty
          node* curr = tail;
          
          while(curr->data != element){
            curr = curr->next;
          }
          //now curr points to the linked list at which element is present
          node* temp = new node(d) ;
          temp->next = curr->next;
          curr->next= temp;
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

 void deletenode(node* tail ,int value){
    //if ll is empty
    if(tail == NULL){
      cout<<"list is empty ,please check again"<<endl;
      return;
    }
  
    else{
      node* prev = tail;
      node* curr = prev->next; 

      while(curr->data != value){
        prev = curr;
        curr = curr->next;
      }
      prev->next = curr->next;

      //if linked list has only one node
      if(curr == prev){
        tail = NULL;
      }

      //if linked list has more than one element
      else if(tail == NULL){
        tail = prev;
      }
      curr->next = NULL;
      delete curr;
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


    return 0;
}