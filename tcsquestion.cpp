//give the sum upto k in fibonaaci series
#include<iostream>
using namespace std;

  int fibonacci(int i){
    if(i<=0)
    return 0;
    if(i==1)
    return 1;
    return fibonacci(i-1)+fibonacci(i-2);
  }
int main(){
     int k , sum =0 ;
     cout<<"enter the integer :";
     cin >> k;

    for( int i=0 ; i <=k ; i++){
          sum =sum +fibonacci(i);
    }

      cout << "sum of fibonacic series is:" <<sum <<endl;
     return 0;

}