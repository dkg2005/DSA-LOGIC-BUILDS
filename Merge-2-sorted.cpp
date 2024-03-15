#include<iostream>
using namespace std;

 void merge(int arr1[], int n ,int arr2[],int m, int arr3[]){
    int i=0, j=0;
     int k = 0;
    while(i<n && j<m){
      if(arr1[i] < arr2[j]){
        arr3[k++] = arr1[i++];
      }
      else {
      	arr3[k++] = arr2[j++];
      }
    }
    while(i<n){
        arr3[k++] = arr1[i++];
    }
    while(j<m){
        arr3[k++] = arr2[j++];
    }
 }
    void print(int arr[], int n){
        for(int i=0; i<n ;i++){
            cout<<arr[i]<<endl;
        }
 }

int main(){

    int arr1[5] = {3,5,7,9,11};
    int arr2[3] = { 1,4,6};
    int arr3[8] = {0};

    cout<<"Before merging the array";
    print(arr1,5);
    cout<<"\n";
    print(arr2,3);
    cout<<endl;
 
    merge(arr1, 5, arr2, 3, arr3);

    cout<<"After merging of array"<<endl;
    print(arr3,8);

     return 0;  
}