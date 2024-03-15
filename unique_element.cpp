  //FOR FINDING UNIQUE ELEMENT IN THE ARRAY
  // in this we have take XOR (^) of all numbers in the array and build this logic 

#include<iostream>
using namespace std;

int unique_element(int *arr , int n){    
      int ans =0 ;
      for(int i=0; i<n ; i++){
        ans =ans^arr[i];
      }
      return ans;
}

int main(){
     int arr1[6] = {1,3,5,5,3,1};
     int arr2[7] = {1,4,5,6,5,4,1};

     int a = unique_element(arr1 ,6);
     cout<<"unique element is:"<<a<<endl;

     int b= unique_element(arr2 ,7);
     cout<<"unique element is:"<<b<<endl;

     return 0;
}