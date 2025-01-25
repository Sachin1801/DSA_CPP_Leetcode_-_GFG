//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> ans(adj.size(),-1);
        queue<int> q;
        q.push(src);
        ans[src]=0;
        vector<bool> visited(adj.size(),false);
        visited[src]=true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();
                q.pop();
                for(auto nbr: adj[top]){
                    if(!visited[nbr]){
                        visited[nbr]=true;
                        ans[nbr]=ans[top]+1;
                        q.push(nbr);
                    }
                        
                }
            }
        }
        return ans;
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends