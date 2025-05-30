class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> dist(n, vector<int>(2,-1));

        dist[node1][0] = 0;
        dist[node2][1] = 0;

        queue<pair<int,int>> q;
        q.push({node1,0});
        q.push({node2,1});

        while(!q.empty()){
            auto& [node_val,type] = q.front();
            q.pop();

            int next_node = edges[node_val];

            if(next_node != -1 and dist[next_node][type] == -1 ){
                dist[next_node][type] = dist[node_val][type] + 1;
                q.push({next_node,type});
            }
        }

        //step 2
        int max_dist = INT_MAX;
        int max_node = INT_MAX;

        for(int i=0;i<n;i++){
            if(dist[i][0] == -1 || dist[i][1]==-1) continue;
            else{
                int max_of_two  = max(dist[i][0], dist[i][1]);
                if(max_of_two < max_dist){
                    max_dist = max_of_two;
                    max_node = i;
                } 
            }
        }
        return max_node == INT_MAX ? -1 : max_node;
    }
};