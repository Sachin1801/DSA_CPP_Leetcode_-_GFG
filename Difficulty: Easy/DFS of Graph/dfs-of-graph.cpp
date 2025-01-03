//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
  public:
    void dfs_helper(int src, vector<vector<int>>& adj, vector<bool> &visited, vector<int> &ans){
        visited[src]=true;
        ans.push_back(src);
        for(const auto nbr: adj[src]){
            if(!visited[nbr])
                dfs_helper(nbr,adj,visited,ans);
        }
        return ;
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        
        vector<bool> visited(adj.size(),false);
        vector<int> ans;
        dfs_helper(0,adj,visited,ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends