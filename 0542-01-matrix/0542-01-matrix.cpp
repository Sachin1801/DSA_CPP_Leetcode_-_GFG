class Solution {
private:
    void compute_4_direction(queue<pair<int,int> > &q, vector<vector<int>> &ans, vector<vector<int>>& mat, pair<int,int> front, int dist){
        int i = front.first;
        int j = front.second;
        if(i+1<mat.size() && mat[i+1][j]==1 && ans[i+1][j]==0){
            ans[i+1][j]=dist+1;
            q.push({i+1,j});
        }
        if(i-1 >= 0 && mat[i-1][j]==1 && ans[i-1][j]==0){
            ans[i-1][j]=dist+1;
            q.push({i-1,j});
        }
        if(j+1<mat[0].size() && mat[i][j+1]==1 && ans[i][j+1]==0){
            ans[i][j+1]=dist+1;
            q.push({i,j+1});
        }
        if(j-1 >=0 && mat[i][j-1]==1 && ans[i][j-1]==0){
            ans[i][j-1]=dist+1;
            q.push({i,j-1});
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int> > ans(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<int,int> > q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto front = q.front();
                q.pop();
                compute_4_direction(q,ans,mat,front,dist);
            }
            dist++;
        }
        return ans;
    }
};