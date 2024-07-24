#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

 Node* insertIntobst(Node* &root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
   
     if( d > root->data ){
        root->right = insertIntobst(root->right, d);
     }
     else{
        root->left = insertIntobst(root->left, d);
     }
     return root;

 }
 void levelOrderTraversal(Node* root){
    if(root == NULL){
        cout<<"Root is Empty"<<endl;
        return;
    }
     queue<Node*> q;

     q.push(root);
     q.push(NULL);   // LEVEL DELIMITER

     while( !q.empty() ){

         Node * temp = q.front();
         q.pop();

         if( temp == NULL ){
            // means old node has complety.
            cout<<endl;
            
            if( !q.empty() ){
                // queue has some still child nodes
                q.push(NULL);
            }
         }

         else{
               cout<< temp -> data <<" " ;

               if(temp -> left){
                    q.push(temp -> left);
               }

               if(temp -> right){
                   q.push(temp -> right);
               }
         }
     }
 }


 void takeInput(Node* &root){
 
   int data;
   cin>> data;

   while(data != -1){
     root = insertIntobst(root,data);
     cin>>data;
   }
 }

int main(){

  Node* Root = NULL;
  
  cout << "Enter the data to create the Binary Search Tree: "<< endl;

    takeInput(Root);

   cout<<"printing the Bst: "<< endl;
    levelOrderTraversal(Root);


    // HERE WE CAN ALSO TRAVERSE IT BY IN,PRE,POST TRAVERSAL
    return 0;
}