#include <bits/stdc++.h>
using namespace std;

int findLCA(int x1, int x2, vector<int>& parent) {
    unordered_set<int> ancestors;
    
    // Store ancestors of x1
    while (x1 != -1) {
        ancestors.insert(x1);
        x1 = parent[x1];
    }

    // Traverse x2 and find the first common ancestor
    while (x2 != -1) {
        if (ancestors.count(x2)) return x2;
        x2 = parent[x2];
    }

    return -1;  // No common ancestor found
}

int main() {
        int N;
        cin >> N;
        vector<int> parent(N);
        for (int i = 0; i < N; i++)  cin >> parent[i];
        int x1, x2;   
        cin >> x1 >> x2;
        cout << findLCA(x1, x2, parent) << endl;
    return 0;
}
