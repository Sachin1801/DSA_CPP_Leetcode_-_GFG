//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void topo_sort(vector<pair<int,int>> Adj[], vector<bool> &visited, stack<int> &s, int node ){
        visited[node]=true;
        for(auto it: Adj[node]){
            if(!visited[it.first])
                topo_sort(Adj,visited,s,it.first);
        }
        s.push(node);
    }
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> Adj[V];
        for(auto edge: edges){
            Adj[edge[0]].push_back({edge[1],edge[2]});
        }
        
        vector<bool> visited(V,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i])
                topo_sort(Adj,visited,s,i);
        }
        vector<int> dist(V,INT_MAX);
        dist[0]=0;
        
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            if(dist[node]!=INT_MAX){
                for(auto it: Adj[node]){
                int v = it.first;
                int wt= it.second;
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node]+wt;
                    }
                }
            }
            
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends