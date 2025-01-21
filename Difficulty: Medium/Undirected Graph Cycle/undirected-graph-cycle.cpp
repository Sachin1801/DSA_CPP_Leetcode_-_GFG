//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    bool detect_cycle(int src, vector<vector<int>>& adj, vector<bool> &visited){
        visited[src]=true;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            for(auto nbr: adj[front.first]){
                if(nbr==front.second)
                    continue;
                else if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push({nbr,front.first});
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<bool> visited(adj.size()); 
        bool ans = false;
        for(int i=0;i<adj.size();i++){
            if(!visited[i])
                ans = detect_cycle(i,adj,visited);
            if(ans==true)
                return true;
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