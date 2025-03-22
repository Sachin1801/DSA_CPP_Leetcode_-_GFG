class Solution {
void dfs(int src, unordered_map<int,vector<int>> &adj, vector<bool> &visited, vector<int> &component){
    visited[src]=true;
    component.push_back(src);
    for(auto nbr: adj[src]){
        if(!visited[nbr]){
            dfs(nbr,adj,visited,component);            
        }
    }
    return ;
}

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(n,false);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int> component;
                int nodes = 0;
                int edge = 0 ;   
                dfs(i,adj,visited,component);
                for(auto node: component){
                    edge += adj[node].size();
                }
                edge /=2; // for each edge is counted twice
                nodes = component.size();
                if(edge == (nodes*(nodes-1))/2) ans++;
            }
        }
        return ans;
    }
};