class Solution {
private:
    queue<pair<int,int>> mark_rotten(pair<int,int> idx, vector<vector<int>>& grid, queue<pair<int,int>> &q, set<pair<int,int>> &s, int &ones){
        int i = idx.first;
        int j = idx.second;
        if(i+1 < grid.size() && grid[i+1][j]==1 && s.find({i+1,j})==s.end()){
            q.push({i+1,j});
            s.insert({i+1,j});
            ones--;
        }
        if(i-1 >=0  && grid[i-1][j]==1 && s.find({i-1,j})==s.end()){
            q.push({i-1,j});
            s.insert({i-1,j});
            ones--;
        }
        if(j-1 >=0  && grid[i][j-1]==1 && s.find({i,j-1})==s.end()){
            q.push({i,j-1});
            s.insert({i,j-1});
            ones--;
        }
        if(j+1 < grid[0].size()  && grid[i][j+1]==1 && s.find({i,j+1})==s.end()){
            q.push({i,j+1});
            s.insert({i,j+1});
            ones--;
        }
        return q;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        pair<int,int> frotten;
        queue<pair<int,int>> q;
        int ones=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    ones++;
            }
        }

        //now we have a starting point
        set<pair<int,int>> s;
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto front = q.front();
                q.pop();
                q = mark_rotten(front,grid,q,s,ones);
            }
            if(!q.empty())
                cnt++;
        }
        if(ones!=0)
            return -1;
        else
            return cnt; 
    }
};