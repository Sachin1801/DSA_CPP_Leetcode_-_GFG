// User function Template for C++

class Solution {
    
    private:
    void findAriticulation(vector<int> adjList[], vector<bool> &visited, 
            vector<int> &time, vector<int> &low, vector<int> &artPts, int src, int parent, int &cTime){
        
        visited[src] = true;
        time[src] = low[src] = cTime++;
        int child= 0 ;
        
        
        //visit all the neighbors
        for(auto &nbr: adjList[src]){
            if(nbr == parent) continue;
            //if not visited
            if(!visited[nbr]){
                findAriticulation(adjList, visited, time, low, artPts, nbr, src, cTime);
                
                low[src] = min(low[src],low[nbr]);
                
                if(low[nbr] >= time[src] && parent !=-1){
                    artPts[src]=1;;
                }
                child++;
            }else{
                low[src] = min(low[src],time[nbr]);
            }
        }
        
        if(child > 1 && parent==-1) artPts[src]=1;
        return;
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int> adjList[]) {
        // Code here
        //we require a visited array 
        vector<bool> visited(V,false);
        // require time array 
        vector<int> time(V);
        //require a lowest it can visit array 
        vector<int> low(V);
        //ds to store the articulation points 
        vector<int> artPts(V,0);
        int cTime = 1;
        
        
        //visit all the vertices if mulitple components given
        for(int i=0;i<V;i++){
            if(!visited[i]){
                findAriticulation(adjList, visited, time, low, artPts, i, -1, cTime);
            }
        }
        
        //compute answer 
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(artPts[i]==1) ans.push_back(i);
        }
        
        //return ans
        if(ans.size()==0 )return {-1};
        return ans;
    }
};