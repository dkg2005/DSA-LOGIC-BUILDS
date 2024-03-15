#include<iostream>
 #include<limits.h>    //for including int_min oor int_max values.
using namespace std;


int largest_row_sum(int arr[][3],int row , int col){
    int maximum = INT_MIN;
    int rowindex = -1;

     for(int i=0;i<3;i++){
        int sum = 0; 
            for(int j=0;j<3;j++){
               sum = sum + arr[i][j];
            }
            if(sum > maximum){
                 maximum = sum ;
                 rowindex = i;
            }       
    }
    cout<<"The largest sum of rows is:-> "<<maximum<<endl;
    return rowindex;
}

int main(){
        
        int arr[3][3];
        cout<<"Enter the elements of 2d array or matrix"<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
            cout<<endl;
        }
        cout<<"The entered matrix is : "<<endl;
         for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }

      int rowindex = largest_row_sum(arr,3,3);
      cout<<"index is:->"<<rowindex;

    return 0;
}