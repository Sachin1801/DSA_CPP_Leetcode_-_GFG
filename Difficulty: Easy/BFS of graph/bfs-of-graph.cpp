//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        queue<int> q;
        
        vector<bool> visited(adj.size(),false);
        visited[0]= true;
        ans.push_back(0);
        q.push(0);
        
        while(!q.empty()){
            int v= q.front();
            q.pop();
            if(v<0 || v>adj.size())
                continue;
            for(auto nbr: adj[v]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                    ans.push_back(nbr);
                }
            }
        }
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

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends