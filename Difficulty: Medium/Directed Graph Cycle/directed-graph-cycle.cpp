class Solution {
  public:
    bool detectCycle(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &path, int curr, int &pathItr){
        //mark it as visted
        visited[curr]=true;
        path[curr]=pathItr;
        
        //check for its directed nbrs
        //case 1: if it is not visited, we call detectCycle on it, with the same pathItr
        // case 2: if it is visited
            // Case 1 : if diffferent path -> continue
            //Case 2: if same path -> cycle detected
        
        for(auto &nbr: adjList[curr]){
            if(!visited[nbr]){
                if(detectCycle(adjList, visited,path, nbr, pathItr)) return true;
            }else{
                if(path[nbr]==path[curr]) return true;
            }
        }
        path[curr]=-1;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(auto &edge: edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visited(V,false);
        vector<int> path(V,-1);
        int pathItr = 1;
        //check for cycle in disconnected graphs for the given edges for V 
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detectCycle(adjList,visited,path,i, pathItr)) return true;
                else{
                    pathItr++;
                }
            }
                
        }
        
        return false;
    }
};