class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<vector<pair<int,int>>> Adj(n+1); 
        for(auto time: times){
            Adj[time[0]].push_back({time[2],time[1]}); //storing wt, v(i)
        }
        vector<bool> visited(n+1,false);
        pq.push({0,k});
        int ans = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int wt = top.first;
            int node = top.second;
            if(visited[node])
                continue;
            ans = max(ans,wt);
            visited[node]=true;
            for(auto nbr: Adj[node]){
                int cost = nbr.first;
                int tonode = nbr.second;
                if(!visited[tonode]){
                    pq.push({wt+cost,tonode});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!visited[i])
                return -1;
        }
        return ans==0? -1: ans;
    }
};