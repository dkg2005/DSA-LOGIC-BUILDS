

// QUESTION:

PRINT THE MAXIMUM ELE OF EACH SUBARRAY OF SIZE K

CODE..

#
// #include<iostream>
// #include<climits>
// #include<set>
// using namespace std;

// int main(){
//     int n,k;
//     cin>>n;
//     cin>>k;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<"elemets are entered"<<endl;
    
    // SLIDING WINDOW  TECHNIQUE
    // multiset<int>st;
    // for(int i=0; i<k; i++){
    //     st.insert(arr[i]);
    // }
    
    // int max_elm = *(--st.end());
    // cout<<max_elm<<endl;
    
    // for(int i=1; i+k-1<n; i++){
    //     st.erase(st.find(arr[i-1]));
    //     st.insert(arr[i+k-1]);
    //     max_elm = *(st.rbegin());
    //      cout<<max_elm<<endl;
        
    // }
    
    // BRUTE FORCE APPROACH
    // for(int i=0; i<=n-k; i++){
    //     int maxi = INT_MIN;
    //     for(int j=i; j<i+k; j++){
    //         maxi = max(maxi, arr[j]);
    //     }
    //     cout<<maxi<<"\t";
    // }
    return 0;
}
#