#include<iostream>
#include <climits>
using namespace std;
 
 // function for finding maximum

 int get_Max( int arr[] , int size){
    int  max = INT_MIN;

    for( int i = 0; i < size ;i++ ){
        if ( arr[i] > max){
            max = arr[i];
        }
    }
    return max;
 } 
 //  function  for  finding minimum 

  int get_Min(int arr[] , int size){
    int min = INT_MAX;

        for( int i = 0 ; i < size ; i++){
            if ( arr[i] < min ){
                min = arr[i];
            }  }
            return min;
  }

int main(){
    int size;
    cin >> size;

    int  arr[100];

    //taking input from the user
    for( int i = 0 ; i < size ; i++){
        cin >> arr[i];
        cout<<"\t";
    }
       cout << endl;

       //displaying required output 
    cout <<"Maximum Number is "<< get_Max(arr, size) <<endl;

     cout <<"Minimum Number is "<< get_Min(arr, size) <<endl;

return 0;
}