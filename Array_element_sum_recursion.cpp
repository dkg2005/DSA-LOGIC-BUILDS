#include<iostream>
using namespace std;

int sum_recursion(int arr[] , int size){
    //base case
    int sum =0 ;
    if( size == 0 ){
        return 0;
    }
    else{
        sum = arr[size-1] + sum_recursion(arr,size-1);
    }
    return sum;
}

int main(){

    int arr[] = {3,2,5,1,6};

     int result = sum_recursion(arr,5) ;

     cout<<"result is: - >> "<< result <<endl;
     
    return 0;
}