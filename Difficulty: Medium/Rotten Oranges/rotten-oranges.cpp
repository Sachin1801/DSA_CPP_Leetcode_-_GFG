class Solution {
    private:
    
    bool isSafe(vector<vector<int>>& mat, int r, int c){
        
        return (r >=0 && r < mat.size() && c >= 0 && c < mat[0].size() && mat[r][c]==1);
    }
    
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        queue<pair<int,int>> q;
        int rowSize = mat.size(), colSize = mat[0].size();
        int freshOranges = 0;
        //level order traversal 
        // i need all the rotten oranges at the same time inside queue
        for(int i=0;i<rowSize; i++){
            for(int j=0; j< colSize;j++){
                //rotten orange
                if(mat[i][j]==2){
                    q.push({i,j});
                }else if(mat[i][j]==1) freshOranges++;
            }
        }
        
        if(freshOranges ==0) return 0;
        
        int totalTime =0;
        
        //bfs on all the rotten eggs at the same time in 4 directions 
        vector<int> dRow = {-1,1,0,0};
        vector<int> dCol = {0,0,-1,1};
        
        
        while(!q.empty()){
            
            int Size = q.size() ; 
            bool rotted = false;
            
            for(int i=0;i< Size; i++){
                
                auto [r,c] = q.front();
                q.pop();
                
                for(int j=0;j<4;j++){
                    //check for all four directions 
                    int nRow = r + dRow[j];
                    int nCol = c + dCol[j];
                    
                    if(isSafe(mat,nRow,nCol)){
                        mat[nRow][nCol]=2;
                        freshOranges--;
                        q.push({nRow,nCol});
                        rotted = true;
                    }
                }
            }
            if(rotted) totalTime++;
        }
        
        return freshOranges  > 0 ? -1 : totalTime;
    }
};