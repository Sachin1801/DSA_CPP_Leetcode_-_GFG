class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> Adj;
        for(auto it: prerequisites){
            Adj[it[1]].push_back(it[0]);
        }
        
        vector<int> inDegree(N,0);
        for(int i=0;i<N;i++){
            for(auto node: Adj[i]){
                inDegree[node]++;
            }
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            topo.push_back(front);
            
            for(auto nbr: Adj[front]){
                inDegree[nbr]--;
                if(inDegree[nbr]==0) q.push(nbr);
            }
        }
        
        if(topo.size()==N) return topo;
        return {};
    }
};