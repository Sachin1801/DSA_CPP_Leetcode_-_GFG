class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size()==0) return true;
        if(graph.size()==1) return false;
        queue<int> q;
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
            }
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(auto nbr: graph[front]){
                    if(color[nbr]==-1){
                        //unvisited nbr
                        color[nbr]=1-color[front];
                        q.push(nbr);
                    }else if(color[nbr]==color[front]) return false;
                }
            }
        }
        return true;
    }
};