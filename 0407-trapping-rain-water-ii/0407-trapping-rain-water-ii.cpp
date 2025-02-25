class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        priority_queue < pair<int, pair<int, int>>,
            vector < pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;

        int vol = 0;
        
        //process the boundires
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || i==r-1 || j==0 || j==c-1){
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        int minBd =0;

        while(!pq.empty()){
            int currHt= pq.top().first;
            int R = pq.top().second.first;
            int C = pq.top().second.second;
            pq.pop();
            minBd = max(currHt, minBd);

            int dr[4]={0,0,-1,1};
            int dc[4]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int rr = R + dr[i];
                int cc = C + dc[i];
                if(rr >=0 && rr < r && cc < c && cc >=0 && vis[rr][cc]==false){
                    pq.push({grid[rr][cc],{rr,cc}});
                    vis[rr][cc]=true;
                    if(grid[rr][cc] < minBd){
                        vol += minBd-grid[rr][cc];
                    }
                }
            }
        }

        return vol;
    }
};