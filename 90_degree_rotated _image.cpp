  //here two functions are made for rotation of image  we reverse the matrix then we take transpose of the matrix
  //also we can do reverse of this.

#include<iostream>
using namespace std;

  void Reverse_of_matrix(int arr[][3], int n){
     int i = 0, j = n-1;
    while(i<=j){
        for(int k =0 ;k<n; k++){
            swap(arr[i][k], arr[j][k]);
        }
        i++;
        j--;
    }
  }
   
   void transpose_of_matrix(int arr[][3],int n){
       for(int i=0; i<n; i++){
        for(int j=0; j<i ;j++){
            swap(arr[i][j],arr[j][i]);
        }
       }
   }

int main(){
    
      int  arr[3][3];
     cout<<"Enter the elements of 2d array or matrix"<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];  
                }
        }
      cout<<"The entered matrix is : "<<endl;
         for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }

         transpose_of_matrix(arr,3);

       Reverse_of_matrix(arr,3);

        cout<<"90deg rotated Matrix: "<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }


}
