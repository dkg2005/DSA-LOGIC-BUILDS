#include<bits/stdc++.h>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int i, int mid, int j){
    int a = i, b = mid+1;
    int k = 0;
    vector<int>temp(j-i+1);
    while(a< mid+1 && b<=j){
        if(arr[a] < arr[b] ){
            temp[k++] = arr[a++];
        }
        else temp[k++] = arr[b++];
    }
    while(a<mid+1){
        temp[k++] = arr[a++];
    }
    while(b<=j){
        temp[k++] = arr[b++];
    }
    k= 0;
    for(int x=i; x<=j; x++){
        arr[x] = temp[k++];
    }
}

void mergesort(vector<int>&arr, int i, int j){
    if(i >= j) return;
    int mid = (i+j)/2;
    mergesort(arr,i,mid);
    mergesort(arr,mid+1,j);
    merge(arr,i,mid,j);
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(auto x : arr){
        cout<<x<<" ";
    }
    return 0;
}