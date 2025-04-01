// question no 2:

// ==================

// You are given a forest (it may contain a single tree or more than one tree) with N nodes.

// Each node is given an integer value 0 to (N­-1).

// You have to find:

// ==================

// Level order traversal: print nodes at every level of the forest.

// N can be very large. Aim for an algorithm with a time complexity of O(N).

// INPUT FORMAT

// ==============

// An integer T, denoting the number of testcases, followed by 2T lines, as each testcase will contain 2 lines.

// First line of each testcase has the value of N.

// Second line of each testcase has list of N values where the number at index i is the parent of node i. The parent of root is -1. ( The index has the range [0, N­-1] ).

// OUTPUT FORMAT

// ================

// For each testcase given, Suppose m is the height of tree, then next m lines must contain the nodes of that level in ascending order separated by space. After printing level order traversal of each testcase, print a new line.

// SAMPLE INPUT

// ================

// 2

// 6

// 5 -1 1 1 5 2

// 13

// 4 3 -1 -1 1 2 7 3 1 4 2 1 2

// SAMPLE OUTPUT

// ===============

// 1

// 2 3

// 5

// 0 4

// 2 3

// 1 5 7 10 12

// 4 6 8 11

// 0 9

// —————

#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

void findLevelOrderTraversal(vector<int>&arr){
    int n = arr.size();
    vector<vector<int>>adj(n);
    queue<int>q;
    for(int i=0; i<n; i++){
        if(arr[i] == -1)   q.push(i);
        else adj[arr[i]].push_back(i);
    }
    while(!q.empty()){
        int size = q.size();
        vector<int>currLevel;
        while(size--){
            int node = q.front();
            q.pop();
            currLevel.push_back(node);
            for(int child : adj[node]) q.push(child);
        }
        // now you can print the current levels node after sorting them
        sort(currLevel.begin(),currLevel.end());
        for(auto num : currLevel){
            cout<<num <<" ";
        }cout<<endl;
    }
}

int main(){
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    findLevelOrderTraversal(arr);
    return 0;
}