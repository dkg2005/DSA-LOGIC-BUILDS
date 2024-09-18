
### QUESTION:

PRINT THE MAXIMUM ELE OF EACH SUBARRAY OF SIZE K



# LOGIC CODE..
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

### QUESTION : 

PRINT THE COUNT OF DISTINCT ELEMNETS OF  THE SUBARRAY OF SIZE K


# LOGIC CODE ..

   ```
// SLIDING WINDOW 
   
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


### QUESTION :
 FIND THE LENGTH OF LONGEST SUBARRAY WITH UNIQUE ELEMENTS 


# LOGIC CODE..
 ```
 //  int maxlen=0;
    // for(int i=0; i<n; i++){
    //      set<int>st; 
    //     for(int j=i; j<n; j++){
    //         if(st.find(arr[j]) != st.end()){
    //             break;
    //         }
    //         st.insert(arr[j]);
    //         maxlen = max(maxlen,j-i+1);
    //     }
    // }

    // SLIDING WINDOW APPROACH WITH VARIABLE size
    int maxlen=0;
    map<int,int>mp;
    int i=0;
    for(int j=0; j<n; j++){
        mp[arr[j]]++;
        while (mp[arr[j]] == 2){
            mp[arr[i]]--;
            i++;
        }
        maxlen = max(maxlen, j-i+1);
    }
    // cout<<maxlen<<endl;
 ```


### QUESTION :

FIND THE LENGTH MAXIMUM FORMED OF CONSCEUTIVE 1'S BY ATMOST K FLIPS .(GIVEN AN BINAY ARRAY AND FLIPING MEANS 1->0)

# CODE LOGIC..
```
// SLIDING WINDOW APPROACH
    int i=0;
    int max_len=0;
    for(int j=0; j<n; j++){
        if(arr[j]==0) k--;
        while(k<0){
            if(arr[i]==0) k++;
            i++;
        }
        max_len = max(max_len,j-i+1);
    }
    
    BRUTE FORCE APPROACH
    int max_len=0;
    for(int i=0; i<n; i++){
        int dupl_k=k;
        for(int j=i; j<n; j++){
            if(arr[j]==0) dupl_k--;
            if(dupl_k<0){
                break;
            }
            max_len = max(max_len,j-i+1);
        }
    }
```