#include<iostream>
#include<queue>
using namespace std;

class heap {
   public:
   int arr[100];
   int size;

   heap(){
    arr[0] = -1;
    size = 0;
   }
     void insert(int val){

        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;   

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
         }
    }

     void print(){
            for(int i = 1; i <= size; i++){
                cout<< arr[i] << " ";
            }cout<<endl;
        }

     void delete_from_heap(){
        if(size == 0){
            cout<<"Nothing to Delete"<<endl;
            return ;
        }
  
   // step - I put last element to the first node
       arr[1]  = arr[size];

   // step - II delete the last node  
       size--;
   
   //  step -III take root node to its correct poistion

        int i = 1;

        while( i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex]){
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex] && arr[rightIndex] > arr[leftIndex]){
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else{
                return ;
            }
        }
     }  
};

void heapify(int arr[], int n , int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n ,largest);
    }
}
 void heapsort(int arr[] , int n){
    
    int size = n ;

    while(size > 1){
        // step -I swap 
        swap(arr[size],arr[1]);
        // step - II decrease the size
        size-- ;
        // step -III now heapify the root node
        heapify(arr,size,1);
    }
 }

int main(){
     
    // heap h;
    // h.insert(60);
    // h.insert(53);
    // h.insert(56);
    // h.insert(40);
    // h.insert(45);

    // h.print();

    // h.delete_from_heap();

    // h.print();

     int arr[6] = {-1, 54, 53, 55, 52, 50 } ;
     int n =5; 

    // building the HEAP
    
     for(int i = n/2 ; i > 0; i--){
        heapify(arr, n, i);
     }
 
    cout<< "printing the array"<<endl;

    for( int i=1 ; i<=n ; i++){
        cout<< arr[i] <<" ";
     }
    cout<<endl;

    // heap sort - >
    heapsort(arr,n);
    cout<<"printing the sorted array"<<endl;
    
    for( int i=1 ; i<=n ; i++){
        cout<< arr[i] <<" ";
     }
      cout<<endl;
     
   // IMPLEMENTATION THROUGH STL
    
    // MAX HEAP
   priority_queue<int> maxheap;
   maxheap.push(10);
   maxheap.push(20);
   maxheap.push(30);
   maxheap.push(40);

   cout<<"top of maxheap is: " << maxheap.top()<<endl;
    maxheap.pop();
   cout<<"top of maxheap is: " << maxheap.top()<<endl;

   cout<< "size is: "<<maxheap.size()<<endl;

        if(maxheap.empty()){
            cout<<"Heap is empty"<<endl;
        }

        else{
            cout<<"Heap is Not empty"<<endl;
        }
  
    cout<< endl;
   // MIN HEAP 
    
    priority_queue<int , vector<int> , greater<int> > minheap;

   minheap.push(10);
   minheap.push(20);
   minheap.push(30);
   minheap.push(40);

   cout<<"top of minheap is: " << minheap.top()<<endl;
    minheap.pop();
   cout<<"top of minheap is: " << minheap.top()<<endl;

   cout<< "size is: "<<minheap.size()<<endl;

        if(minheap.empty()){
            cout<<"Heap is empty"<<endl;
        }

        else{
            cout<<"Heap is Not empty"<<endl;
        }
  
    return 0;
}