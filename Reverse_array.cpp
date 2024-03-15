#include<iostream>
using namespace std;
//function for reversing the array
void reverse(int arr[], int n){
   int start = 0;
   int end  = n-1;

   while(start<=end){
    swap(arr[start],arr[end]);
    start++;
    end--;
   }
}
//function for printing the array
void printarray(int arr[], int n){
    for(int i=0 ; i<n ;i++){
        cout<< arr[i] << "\t";
    }
    cout<<endl;
}

int main(){
    int arr[6] = {1,2,3,4,5,6}; 
    int brr[5] = {7, 8 , 9, 10, 11};
//reversing the array
    reverse(arr,6);
    reverse(brr,5);
//printing the reversed array
    printarray(arr,6);
    printarray(brr,5);
    return 0;
}