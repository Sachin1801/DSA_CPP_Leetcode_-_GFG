//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    private:
    bool detect_cycle(int src, vector<vector<int>>& adj, vector<bool> &visited, int parent){
            visited[src]=true;
            for(auto nbr: adj[src]){
                if(!visited[nbr]){
                    if(detect_cycle(nbr,adj,visited,src))
                        return true;
                }
                else if(nbr!=parent){
                    return true;
                }
            }
            return false;
        }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect_cycle(i,adj,visited,-1))
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends