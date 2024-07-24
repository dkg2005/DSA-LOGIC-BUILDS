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

  Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp -> left;
    }
    return temp;
  }

  Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp -> right;
    }
    return temp;
  }

  Node* deleteFromBST(Node* root, int val){
      
      if(root == NULL)
        return  root;

    if(root->data == val){
        // 0 child handle
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child handle

        //left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
 
        //2 child handle
         if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
           root->right =  deleteFromBST(root->right, mini);
            return root;
         }
 
    }
     
    else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
      
    else{
        root->right = deleteFromBST(root->right,val);
        return root;
    }
  }

int main(){

  Node* Root = NULL;
  
  cout << "Enter the data to create the Binary Search Tree: "<< endl;

    takeInput(Root);

    cout<<"printing the Bst: "<< endl;
    levelOrderTraversal(Root);

    cout<<endl;
    // HERE WE CAN ALSO TRAVERSE IT BY IN,PRE,POST TRAVERSAL

//    Node* temp = minVal(Root);
//    cout<<"Minimum value is: "<<temp->data<<endl;

//     temp = maxVal(Root);
//    cout<<"Maximum value is: "<<temp->data<<endl;


  //    Root = deleteFromBST(Root, 30);

   Root = deleteFromBST(Root, 50);
      
        cout<<"printing the Bst: "<< endl;
          levelOrderTraversal(Root);

   
    return 0;
}