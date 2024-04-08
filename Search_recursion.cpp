#include<iostream>
using namespace std;

bool is_sorted(int arr[] , int size){
    //base case
    if(size == 0  || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool ans = is_sorted(arr+1 ,size-1);
        return ans;
    }

}

int main(){
    int arr[5] = {1,2,9,4,5};
   
      bool result = is_sorted( arr ,5 );

      if (result){
        cout<<" Given Array is Sorted"<<endl;
      }
      else{
        cout<<" Given Array is NOT Sorted"<<endl;
      }
      return 0;
}