#include<iostream>
using namespace std;

class node{
    public: 

    int data;
    node* left;
    node* right;

    public:
    node(int data){
        cout<<"A new node is declared "<<endl;
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    
    cout<<"Enter the data which you want to insert : " <<endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data which you want to insert in the left :"<< data <<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data which you want to insert in the right : "<< data <<endl;
    root->right = buildTree(root->right);

  return root;
}


int main(){

    node* root = NULL;
    buildTree(root);
    

    return 0;
}