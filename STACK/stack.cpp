 // IMPLEMENTATION THROUGH STL, ARRAY, LINKED LIST
 
#include<iostream>
 // #include<stack>
using namespace std;

class Stack{
    public:
    int * arr;
    int top ;
    int size ;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

// PUSH FUNCTION 

     void push(int element){
        if(size - top >1){
            top++;
            arr[top] = element;}
        else{
            cout<< "STACK UNDERFLOW" <<endl;}
        
     }
 
 //   POP FUNCTION
   
     void pop(){

        if(top >=0){
               top--;
        }
        else
            cout<< "STACK UNDERFLOW" <<endl;
     }

//   PEEK FUNCTION
  
    int peek(){
        if(top >= 0)
            return arr[top];
        else
           cout<<"Stack is empty"<<endl;
           return -1;
    }


// EMPTY FUNCTION

    bool empty(){

        if(top == -1)
           return true;
        else
        return false;

    }
};
int main(){
   

    Stack stack(5);

    stack.push(12);
    stack.push(14);
    stack.push(19);

    cout<<stack.peek()<<endl;

    stack.pop();

    cout<< stack.peek()<<endl;

    cout<<"Check stack is empty or not "<< stack.empty() <<endl ;
    stack.pop();
    stack.pop();
    cout<<"Check stack is empty or not "<< stack.empty() <<endl ;
   /*

    stack<int> s;
   
    s.push(2);
    s.push(3);
    s.push(5);
   
    // SIZE of the stack
     cout<<"size of the stack is: "<<s.size();

   // last element was pushed is 5 wchich is on the top
    cout<<"printing top element : "<<s.top()<<endl;
 
   // printing all the elemets of the stack
    while(s.top() != -1){
        cout<<s.top()<<endl;
        s.pop();
    }
   
    // to check the stack is empty or not
    if(s.empty()){
        cout<<"stack is empty" << endl;
    }
    
    else{
        cout<<"not empty"<<endl;
    }
  
   */
    return 0;
}