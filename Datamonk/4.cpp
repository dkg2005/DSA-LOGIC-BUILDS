#include<bits/stdc++.h>
using namespace std;

void fxn(unordered_map<int,int>&hash, int user){
    // if it is alread presnt in it , then just increase its freq by 1 and return
    if(hash.find(user) != hash.end()){
        hash[user]++;
        return;
    }
     if(hash.size() < 5){
        hash[user]++;
        return;
    }
    //Now i have to find that user which has minimum freq and replace it with the new user
    int tempUser = -1;
    int tempFreq = 10; // let suppose maximum user is 10
    for(auto x : hash){
        if(x.second <= tempFreq){
            tempUser = x.first;
            tempFreq = x.second;
        }
    }
    // now just remove the old least one user and add the new user in the chache
    hash.remove(tempUser);
    hash[user]++;
}

int main(){
    unordered_map<int,int>hash;
    unordered_set<int>st;
    int n ;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        st.insert(temp);
    }

    fxn(hash,1);

    return 0;
}