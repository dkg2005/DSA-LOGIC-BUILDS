#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void fxn(unordered_map<char,int>&hash, char user, int&time){
    if(hash.find(user)!= hash.end()){ // if user is already present
        hash[user] = time++;
        return;
    }
    int tempTime = INT_MAX;  // now i have to check the user which have least time
    char tempUser = 'z';
    for(auto x : hash){
        char u = x.first;
        int t = x.second;
        if(tempTime > t){
            tempTime = t;
            tempUser = u;
        }
    } // now i have user with the lowest time
    hash.erase(tempUser);
    hash[user] = time++;
}
int main(){
    int time = 0;
    unordered_map<char,int>hash; // {user,time}
    hash['a'] = time++;
    hash['b'] = time++;
    hash['c'] = time++;
    hash['d'] = time++;
    // cout<<time<<endl;
    fxn(hash,'e',time);
    // to acess
    if(hash.find('a') == hash.end()){
        cout<<"This is not cache"<<endl;
    }
    // acess
    cout<<hash['e']<<endl;
    return 0;
}