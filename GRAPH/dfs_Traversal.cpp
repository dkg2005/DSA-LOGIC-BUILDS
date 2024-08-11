#include <iostream>
#include <vector>
using namespace std;

// dfs traversal of undirected graph

void addEdge(vector<vector<int>> &adj, int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s); // Remove this line
                         // for directed graphs
}

// Prints all reachable vertices from s in DFS manner
void DFSRec(vector<vector<int>> &adj, 
              vector<bool> &visited, int s) {
  
    // Mark s as visited and print it
    visited[s] = true;
    cout << s << " ";

    // Recursively call for all adjacent
    // that are not visited yet/
    for (int i : adj[s]) {
        if (!visited[i])
            DFSRec(adj, visited, i);
    }
}

// The main DFS function. This function 
// mainly calls DFSRec()
void DFS(vector<vector<int>> &adj, int s) {
    int V = adj.size();
    vector<bool> visited(V, false);
    DFSRec(adj, visited, s); 
}

// Driver code
int main() {
    int V = 4; // Number of vertices in the graph
    vector<vector<int>> adj(V);


    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";

    DFS(adj, 2);

    return 0;
}
