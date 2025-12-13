class Solution {
private:
    void dfs(vector<vector<int>> &adjList, vector<bool> &visited, stack<int> &st, int curr){
        visited[curr]= true;
        
        //check for all its nbrs
        //Case 1: if it is already visited-> do nothing 
        //Case 2 : if not visited
            // call dfs on it
            
        for(auto &nbr: adjList[curr]){
            if(!visited[nbr]){
                dfs(adjList,visited, st,nbr);
            }
        }
        st.push(curr);
        return;
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        // make the adjList 
        vector<vector<int>> adjList(V);
        
        for(auto &edge : edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        
        //run for all vertices
            //for disconnected components too
        vector<bool> visited(V, false);
        stack<int> st;
            
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adjList, visited,st, i);
            }
                
        }
        
        
        vector<int> ans;
        
        while(!st.empty()){
            int topVal = st.top();
            st.pop();
            
            ans.push_back(topVal);
        }
        
        return ans;
    }
};