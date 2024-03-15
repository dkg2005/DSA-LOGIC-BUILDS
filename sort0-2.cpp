#include<iostream>
using namespace std;

void sort012(int *arr, int n) {

    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count0++;
        }
        else if (arr[i] == 1) {
            count1++;
        }
        else if (arr[i] == 2) {
            count2++;
        }
    }

    for(int i=0; i<count0 ;i++){
      arr[i]=0;
   } 
   for(int i=count0; i<count1 ;i++){
      arr[i]=1;
   } 
    for( int i=count1; i<count2 ; i++){
       arr[i]=2;
    } 
}

int main() {
    int arr[6] = {0, 1, 2, 2, 1, 0};
    int n = 6;
    sort012(arr, n);
    return 0;
    for(int i =0; i<n ; i++){
        cout<<arr[i];
    }
}
