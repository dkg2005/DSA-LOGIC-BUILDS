

// QUESTION:

PRINT THE MAXIMUM ELE OF EACH SUBARRAY OF SIZE K



# CODE..
 ```
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
```

//QUESTION : PRINT THE COUNT OF DISTINCT ELEMNETS OF  THE SUBARRAY OF SIZE K


# CODE ..
// SLIDING WINDOW 
   
   ```
    // map<int,int>mp;
    // for(int i=0; i<k; i++){
    //     mp[arr[i]]++;
    // }
    // cout<<mp.size()<<endl;
    
    // for(int i=1; i<=n-k; i++){
        
    //     mp[arr[i-1]]--;
        
    //     if(mp[arr[i-1]] == 0){
    //         mp.erase(arr[i-1]);
    //     }
    //      mp[arr[i+k-1]]++;
    //      cout<<mp.size()<<endl;
         
    // }
    ```