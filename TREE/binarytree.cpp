#include<iostream>
#include<queue>
using namespace std;

class node{
    public: 

    int data;
    node* left;
    node* right;

    public:
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    
    cout<<"Enter the data : " <<endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data which you want to insert in the left of"<< data <<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data which you want to insert in the right of "<< data <<endl;
    root->right = buildTree(root->right);

  return root;
}

 void levelOrderTraversal(node* root){
    if(root == NULL){
        cout<<"Root is Empty"<<endl;
        return;
    }
     queue<node*> q;

     q.push(root);
     q.push(NULL);   // LEVEL DELIMITER

     while( !q.empty() ){

         node * temp = q.front();
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

 void inorderTraversal(node* root){
    // [ LRN ]
    if(root == NULL){
        return ;
    }
     
     inorderTraversal(root -> left);     
     cout<< root -> data << " ";
     inorderTraversal(root -> right);     
 }

   void preorderTraversal(node* root){
    // [ NLR ]
    if(root == NULL){
        return ;
    }

     cout<< root -> data << " ";
     preorderTraversal(root -> left);     
     preorderTraversal(root -> right);     
 }
  
   void postorderTraversal(node* root){
    // [ LRN ]
    if(root == NULL){
        return ;
    }
     
     postorderTraversal(root -> left);       
     postorderTraversal(root -> right);    
     cout<< root -> data << " "; 
 }

  void buildfromLevelOrder(node* &root){
     queue<node*>q;

     cout<<"Enter the data of root node: "<<endl;
     int data;
     cin>> data;
     root = new node(data);
     q.push(root);

     while(!q.empty()){
        node* temp = q.front();
        q.pop();

           cout<<"Enter the left node data of :" << temp->data <<endl;
           int leftData;
           cin>>leftData;

            if(leftData != -1) {
               temp -> left = new node(leftData);
                q.push(temp->left);
            }

           cout<<"Enter the right node data of :" << temp->data <<endl;
           int rightData;
           cin>>rightData;
   
           if(rightData != -1) {
                temp -> right = new node(rightData);
                q.push(temp->right);
            }

     }
  }

int main(){

    node* root = NULL;
   //   root = buildTree(root);

    // 1 2 4 -1 -1 5 -1 -1 3 7 -1 -1 8 -1 -1 -1 -1 -1

    buildfromLevelOrder(root);
    levelOrderTraversal(root);


    //   cout << endl << "The inOrderTraversal of the tree is :  " ;
    //   inorderTraversal(root);

    //   cout << endl << "The preOrderTraversal of the tree is :  " ;
    //   preorderTraversal(root);

    //   cout << endl << "The postOrderTraversal of the tree is :  " ;
    //   postorderTraversal(root);


    return 0;
}