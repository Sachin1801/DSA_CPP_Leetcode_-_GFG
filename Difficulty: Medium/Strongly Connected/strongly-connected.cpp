//Position this line where user code will be pasted.
class Solution {
    private:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited,stack<int> &st, int src){
        visited[src]=true;
        
        for(auto &nbr: adj[src]){
            if(visited[nbr]==false){
                dfs(adj,visited,st,nbr);  
            } 
        }
        
        st.push(src);
    }
    
    void dfs2(vector<vector<int>> &adj, vector<bool> &visited, int src){
        visited[src]=true;
        
        for(auto &nbr: adj[src]){
            if(visited[nbr]==false){
                dfs2(adj,visited,nbr);  
            } 
        }
        
    }
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        
        //I have to get the edges based on finish time 
        int V = adj.size();
        vector<bool> visited(V,false);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs(adj,visited,st,i);
            }    
        }
        
        
        //step one is to reverse all the edges 
        vector<vector<int>> adjList(V);
        
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                int v = adj[i][j];
                adjList[v].push_back(i);
            }
        }
        
        visited.assign(V,false);
        int scc=0;
        
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(visited[t]==false){
                dfs2(adjList,visited,t);
                scc++;
            }
        }
        
        return scc;
    }
};