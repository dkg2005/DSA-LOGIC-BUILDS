#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

using namespace std;

void dfs(int node, int parent, vector<int>& A, vector<vector<int>>& adj, vector<vector<int>>& dp, int K) {
    dp[node][0] = 1;  // There's always one way to have sum 0: choose no nodes
    if (A[node] <= K) {
        dp[node][A[node]] = 1;
    }

    for (int child : adj[node]) {
        if (child == parent) continue;
        dfs(child, node, A, adj, dp, K);
        vector<int> new_dp(K + 1, 0);
        for (int i = 0; i <= K; ++i) {
            if (dp[node][i] > 0) {
                for (int j = 0; j <= K - i; ++j) {
                    if (dp[child][j] > 0) {
                        new_dp[i + j] = (new_dp[i + j] + 1LL * dp[node][i] * dp[child][j]) % MOD;
                    }
                }
            }
        }
        dp[node] = new_dp;
    }
}

int find_sum_of_F_U_K(int N, int M, int K, vector<int>& A, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(N);
    for (auto& edge : edges) {
        int u = edge.first - 1;
        int v = edge.second - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> dp(N, vector<int>(K + 1, 0));
    
    dfs(0, -1, A, adj, dp, K);
    
    int result = 0;
    for (int u = 0; u < N; ++u) {
        result = (result + dp[u][K]) % MOD;
    }
    
    return result;
}

int main() {
    int N, M, K;
    cin >> N;
    cin >> M;
    cin >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    cout << find_sum_of_F_U_K(N, M, K, A, edges) << endl;
    return 0;
}















/*
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> graph;
vector<int> values;
vector<vector<int>> dp;

void dfs(int u, int p, int K) {
    dp[u][0] = 1;
    for (int v : graph[u]) {
        if (v != p) {
            dfs(v, u, K);
            for (int i = K; i >= 0; i--) {
                for (int j = min(i, values[v]); j >= 0; j--) {
                    dp[u][i] = (dp[u][i] + 1LL * dp[u][i - j] * dp[v][j]) % MOD;
                }
            }
        }
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    graph.resize(N + 1);
    values.resize(N + 1);
    dp.resize(N + 1, vector<int>(K + 1));

    for (int i = 1; i <= N; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1, K);

    int ans = 0;
    for (int i = 0; i <= K; i++) {
        ans = (ans + dp[1][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
// */