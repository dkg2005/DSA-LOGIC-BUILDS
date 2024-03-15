#include<iostream>
using namespace std;

int main(){
        
        int arr[3][2];
        cout<<"Enter the elements of 2d array or matrix"<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                cin>>arr[i][j];
            }
            cout<<"\n";
        }
        cout<<"The entered matrix is : "<<endl;
         for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<"\n";
        }

    return 0;
}