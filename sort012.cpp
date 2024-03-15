#include<iostream>
using namespace std;

void sort012(int *arr, int n){

   int i;
   int count0=0 , count1=0, count2=0 ;
   for(int i=0; i<n; i++){
      if(arr[i]==0){
         count0++;
      }
      else if (arr[i]==1){
         count1++;
      }
      else{
         count2++;
      }  


      cout<<" count0 :"<<count0<<endl;
      cout<<" count1 :"<<count1<<endl;
      cout<<" count2 :"<<count2<<endl; 
}


