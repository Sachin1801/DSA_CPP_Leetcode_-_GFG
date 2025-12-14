class Solution {
    
    private:
    bool dfs(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &time, vector<int> &low, int &cTime, int src, int par, int c, int d){
        visited[src] = true;
        time[src] = cTime;
        low[src] = cTime;
        cTime++;
        //visit all of its nbrs
        for(auto &nbr: adjList[src]){
            if(nbr==par) continue;
            if(visited[nbr]){
                low[src] = min(low[src],time[nbr]);
            }else{
                if(dfs(adjList, visited, time,low,cTime,nbr,src,c,d )){
                    return true;
                }
                low[src] = min(low[nbr],low[src]);
                
                if(low[nbr] > time[src] && ((src == c && nbr == d) || (nbr == c && src == d)) ) return true;
                
            }
            
        }
        return false;
    }
    
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        //we need to have a visited array 
        vector<bool> visited(V,false);
        
        //we would need a time array
        vector<int> time(V);
        // low time array, to get the min insertion time of all the nbrs, expcept the parent 
        vector<int> low(V);
        
        //adjList from edges
        vector<vector<int>> adjList(V);
        
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        

        int parent = -1;
        int cTime = 1;        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adjList, visited, time, low,cTime, i, parent, c, d)){
                    return true;
                }
            }
        }
        
        return false;
    }
};