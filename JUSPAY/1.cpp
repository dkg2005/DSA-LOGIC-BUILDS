// Question 1 
// You are given a forest (it may contain a single tree or more than one tree) with N nodes.

// Each node is given an integer value 0 to (N­-1).

// You have to find:

// ===================

// The depth of forest at which maximum number of nodes are present.

// N can be very large. Aim for an algorithm with a time complexity of O(N).

// INPUT FORMAT

// =================

// An integer T, denoting the number of testcases, followed by 2T lines, as each testcase will contain 2 lines.

// First line of each testcase has the value of N.

// Second line of each testcase has list of N values where the number at index i is the parent of node i. The parent of root is -1. ( The index has the range [0, N­-1] ).

// OUTPUT FORMAT

// ===============

// For each testcase given, output a single line that has the depth of forest at which maximum number of nodes are present. If multiple depths has same number of nodes, then deepest depth should be selected.

// SAMPLE INPUT

// ==============

// 2

// 6

// 5 -1 1 1 5 2

// 13

// 4 3 -1 -1 1 2 7 3 1 4 2 1 2

// SAMPLE OUTPUT

// ====================

// 3

// 1

// (the above diagram is common for all 3 questions)


#include<iostream>
#include<vector>
#include<queue>
#include <bits/stdc++.h>
using namespace std;
int findMaxDepth(vector<int>&arr){
    int n = arr.size();
    vector<vector<int>>adj(n); // firslty create the adjacent list
    vector<int>depthCnt(n,0); // to cnt the no of nodes at that specific depth
    queue<pair<int,int>>que; // to apply bfs

    for(int i=0; i<n ;i++){
        if(arr[i] == -1) que.push({i,0}); // this is a root node so {node,depth} we are pusshing intially in our queue
        else adj[arr[i]].push_back(i); // to make the adjacent list {parent->childs}
    }
    int maxDepth = 0, maxNodes = 0;
    while(!que.empty()){
        int node =  que.front().first;
        int depth = que.front().second;
        que.pop();
        depthCnt[depth]++;
        if(depthCnt[depth] > maxNodes || (depthCnt[depth] == maxNodes && depth > maxDepth)){
            maxNodes = depthCnt[depth];
            maxDepth =  depth;
        }
        for(auto child : adj[node]){
            que.push({child,depth+1});
        }
    }
    cout<<maxDepth<<endl;
    return maxDepth;
}

int main(){
    int n ;
    cin>>n;
    vector<int>arr(n); // its the parent array which is given
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<findMaxDepth(arr);
    return 0;
}
