//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
        
    
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<vector<pair<int,int>>> Adj(V); 
        for(int u = 0; u < V; u++) {
            for(auto vec : adj[u]) { // adj[u] contains {v, weight}
                int v = vec[0], wt = vec[1];
                Adj[u].push_back({v, wt});
                Adj[v].push_back({u, wt}); // Undirected graph
            }
        }

        vector<bool> visited(V,false);
        int cost = 0;
        int visitedtrue = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                pq.push({0,i});
                while(!pq.empty()){
                    auto top = pq.top();
                    pq.pop();
                    if(!visited[top.second]){
                        cost+= top.first;
                        visited[top.second]=true;
                        visitedtrue++;
                    }
                    if(visitedtrue ==V)
                        return cost;
                    for(auto pair: Adj[top.second]){
                        if(!visited[pair.first]){
                            pq.push({pair.second,pair.first});
                        }
                    }
                }
                
            }
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends