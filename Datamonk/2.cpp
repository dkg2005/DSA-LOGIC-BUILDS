#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
   vector<int>temp(n,0);
    int i =0;
    int j = k;
    while(i<n-k){
        temp[i++] = arr[j++];
    }
    j=0;
    while(j<k){
        temp[i++] = arr[j++];
    }
    cout<<"Final Rotated Array"<<endl;
    for(int k=0; k<n; k++){
        cout<<temp[k]<<" ";
    }
    
    return 0;
}


// cin>>n;
//     if(n%5 == 0  && n%3 == 0){
//         cout<<"FIZZ BUZZ" <<endl;
//     }
//     else if(n%3 == 0){
//         cout<<"FIZZ"<<endl;
//     }
//     else if(n%5 == 0){
//         cout<<"BUZZ"<<endl;
//     }