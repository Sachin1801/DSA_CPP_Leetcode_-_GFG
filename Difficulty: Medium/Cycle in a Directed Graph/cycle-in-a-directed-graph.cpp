//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    bool dfs_detectCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
        visited[src] = true;
        recStack[src] = true; // Mark node as part of the current recursion stack

        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
                // Recursive call for unvisited neighbors
                if (dfs_detectCycle(nbr, adj, visited, recStack)) {
                    return true; // Cycle detected
                }
            } else if (recStack[nbr]) {
                // Back edge found (neighbor is in the current recursion stack)
                return true;
            }
        }

        recStack[src] = false; // Remove the node from the recursion stack
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false); // Tracks the recursion stack

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs_detectCycle(i, adj, visited, recStack)) {
                    return true; // Cycle detected
                }
            }
        }

        return false; // No cycle found
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends