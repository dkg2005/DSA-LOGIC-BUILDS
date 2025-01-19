#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Heap{
    public: 
     int heap[100], size;

     Heap(){
        heap[0] = -1;
        size = 0;
     }
     void insert(int val){
        size = size + 1;
        heap[size] = val;
        int idx = size;
        while(idx > 1){
            if(heap[idx]>heap[idx/2]){   // parent idx is -> idx/2
                swap(heap[idx], heap[idx/2]);
                idx = idx / 2;  //  also updating index for next checking
            }
            else return;
        }
    }

    void deleteNode(){  // fxn to deleteNode from the heap 
        if(size <= 0) 
            cout<<"Deletion is not possible "<<endl;
        heap[1] = heap[size];
        size = size - 1;
        int i = 1;
        while(i <= size/2){
            int leftChild = heap[2*i];
            int rightChild = heap[2*i+1];
            if(heap[i]<leftChild && leftChild>rightChild){
                swap(heap[i],heap[2*i]);
                i = 2*i;
            }
            else if(heap[i]<leftChild && leftChild<rightChild){
                swap(heap[i],heap[2*i+1]);
                i = 2*i + 1;
            }
            else break;
        }
    }

    void heapify(int arr[], int n, int i){
        int largestElIdx = i;
        int leftIdx = 2*i;
        int rightIdx = 2*i+1;
        if(leftIdx <= n && arr[largestElIdx] < arr[leftIdx]){
            largestElIdx = leftIdx;
        }
        if(rightIdx <= n && arr[largestElIdx] < arr[rightIdx]){
            largestElIdx = rightIdx;
        }
        if(largestElIdx != i){
            swap(arr[largestElIdx],arr[i]);
            heapify(arr,n,largestElIdx);
        }
    }

    void heapSort(int arr[], int n){
        int size = n;

        while(size > 1){
            swap(arr[size],arr[1]);
            size--;
            heapify(arr,size,1); 
        }
    }
    void print(){
        cout<<" PRINTING THE HEAP :  ";
        for(int i=1; i<=size; i++)
            cout<<heap[i]<<" ";
    }
};

int main(){
    cout<<"HEAPS INSERTIION || "<<endl;
    Heap hp;
    hp.insert(60);
    hp.insert(50);
    hp.insert(30);
    hp.insert(20);
    hp.insert(40);
    hp.insert(55);
    hp.print();
    // cout<<"Deletion in Heap : 1 st time :  " ;
    // hp.deleteNode();
    // hp.print();
    // cout<<"Deletion in Heap : 2 st time :  " ;
    // hp.deleteNode();
    // hp.print();
    //  cout<<"Deletion in Heap : 3 st time :  " ;
    // hp.deleteNode();
    // hp.print();
    //  cout<<"Deletion in Heap : 4 st time :  " ;
    // hp.deleteNode();
    // hp.print();

    int arr[] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i=n; i>0; i--){
        hp.heapify(arr,n,i);
    }
    cout<<"After the heapify : " ;
    for(int i=1;i<6; i++){
        cout<<arr[i]<<"  ";
    } cout<<endl;

    hp.heapSort(arr,n);
    cout<<"After the heap sort : " ;
    for(int i=1;i<6; i++){
        cout<<arr[i]<<"  ";
    }

    return 0;
}