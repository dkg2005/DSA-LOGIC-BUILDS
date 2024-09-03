#include<iostream>
#include<vector>
using namespace std;

void reverse(int arr[], int s, int e){
    while(s <= e){
        swap(arr[s++],arr[e--]);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        if(arr[i]==0){
            reverse(arr,0,i-1);
        }
    }
    
    //print
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}