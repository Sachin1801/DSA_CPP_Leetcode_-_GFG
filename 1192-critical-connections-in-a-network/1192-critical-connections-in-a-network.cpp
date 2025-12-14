class Solution {
public:

    void dfs(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &time, vector<int> &low,
                            vector<vector<int>> &edges, int &cTime,int  src, int par){
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
                dfs(adjList,visited,time, low,edges, cTime, nbr, src);
                low[src] = min(low[src],low[nbr]);

                if(low[nbr] > time[src]){
                    edges.push_back({src,nbr});
                }
            }
        }
        return;
    }

    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& connections) {
        vector<bool> visited(V,false);
        
        //we would need a time array
        vector<int> time(V);
        // low time array, to get the min insertion time of all the nbrs, expcept the parent 
        vector<int> low(V);
        
        //adjList from edges
        vector<vector<int>> adjList(V);
        
        for(auto& edge: connections){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<vector<int>> edges;

        int curr= 1;
        int parent = -1;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adjList, visited, time, low,edges,curr, i, parent);
            }
        }
        
        return edges;
    }
};