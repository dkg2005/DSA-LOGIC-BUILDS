#include<iostream>
using namespace std;
  int rotate(int arr[], int n, int k) {
    int rotated[n]; // Create a new array with the same
    for(int i =0; i<n; i++){
     rotated[(i+k)%n] = arr[i];
    }
    return rotated;
  }
  void print_array(int *arr[], int n){
    for(int i =0 ;i<n ;i++){
        cout<<arr[i]<<"\t";
    }
  }

int main(){
    int arr1[] ={1,2,3,4,5,6,7};
    int arr2[] ={-1,34, 67, 99};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
     
     cout<<"before rotation:->"<<endl;
      print_array (arr1,n);
      print_array (arr2,m);

    // k is integer to show the no of steps array is rotated
      int *result1 = rotate(arr1, n, 3);
      int *result2 = rotate(arr2, m ,2);

       cout<<"after rotation:->"<<endl;

      print_array (result1,n);
      print_array (result2,m);

         delete[] result1;
         delete[] result2;

     return 0;
}