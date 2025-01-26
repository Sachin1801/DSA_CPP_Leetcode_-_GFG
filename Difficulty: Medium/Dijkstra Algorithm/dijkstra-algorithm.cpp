//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int V = adj.size();
        vector<int> dist(V,1e9);
        dist[src]=0;
        set<pair<int,int>>s;
        s.insert({0,src});
        while(!s.empty()){
            auto top = *(s.begin()); 
            int node = top.second;
            int dis = top.first;
            s.erase(top);
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[v] > dist[node]+wt){
                    if(s.find({dist[v],v})!=s.end()){
                        s.erase({dist[v],v});
                    }
                    dist[v]=dist[node]+wt;
                    s.insert({dist[v],v});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends