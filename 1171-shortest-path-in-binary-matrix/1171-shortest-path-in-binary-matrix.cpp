class Solution {

private:
    bool check(int newrow, int newcol ,int row, int col){
        return (newrow < row and newrow >=0 and newcol<col and newcol >=0);
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int rowsize = grid.size();
        int colsize = grid[0].size();
        pair<int,int> source = {0,0};
        pair<int,int> destination = {rowsize-1,colsize-1};
        vector<vector<int>> distance(rowsize,vector<int>(colsize,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        //right, left, down, up, bottom right, bottom left, top left, top right
        vector<pair<int,int>> directions={{0,+1},{0,-1},{+1,0},{-1,0},{+1,+1},{+1,-1},{-1,-1},{-1,+1}};
        q.push({1,source});
        distance[source.first][source.second]=1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int dist = front.first;
            int row = front.second.first;
            int col = front.second.second;
            if(row==destination.first and col == destination.second) return dist;
            //four directions
            for(int i=0;i<directions.size();i++){
                auto p = directions[i];
                int newrow = row + p.first;
                int newcol= col + p.second;
                if((check(newrow,newcol,rowsize,colsize)==true) and (grid[newrow][newcol]==0) and (distance[newrow][newcol]> dist+1)){
                    distance[newrow][newcol] = dist + 1;
                    q.push({dist+1,{newrow,newcol}});
                }
            }
        }
        return -1;
    }
};