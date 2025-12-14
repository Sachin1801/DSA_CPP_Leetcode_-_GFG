class Solution {
  public:
  
    void dfs(vector<vector<int>> &AdjList, vector<int> &visited, vector<int> &tin, vector<int> &low, vector<int> &mark,int src, int parent, int &cTime){
        
        visited[src] = 1;
        tin[src] = cTime;
        low[src] = cTime++;
        
        int child = 0;
        //visit all its nbrs
        for(auto &nbr: AdjList[src]){
            // as we cannot cut it from the parent : algo
            if(nbr==parent) continue;
            
            if(visited[nbr]==0){
                dfs(AdjList, visited, tin, low, mark, nbr, src, cTime);
                
                low[src] = min(low[src], low[nbr]);
                
                if(low[nbr] >= tin[src] && parent!=-1 ){
                    mark[src] =1;
                }
                child++;
            }else{
                low[src] = min(low[src],tin[nbr]);
            }
        }
        
        if(parent == -1 && child > 1 ){
            mark[src] = 1;
        }
    }
  
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        
        //form the adj matrix
        vector<vector<int>> adjList(V);
        for(auto &edge: edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        //data structures: visited, tin, low,mark the artPoints
        
        vector<int> visited(V,0), tin(V), low(V), mark(V,0);
        
        //check for all different components given
        int cTime= 0;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(adjList, visited, tin, low,mark, i, -1, cTime);
            }
        }
        
        //get all the articulation poitns
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0) return {-1};
        return ans;
        
    }
};