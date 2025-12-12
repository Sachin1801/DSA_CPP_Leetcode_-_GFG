class Solution {
private:

    bool isSafe(vector<vector<int>>& image, vector<vector<bool>> &visited, int r, int c, int oldColor){
        return (r >=0 && r < image.size() && c >=0 && c < image[0].size() && visited[r][c]==false && image[r][c]==oldColor);
    }

    void bfs(vector<vector<int>>& image,vector<vector<bool>> &visited, int sRow, int sCol, int oldColor, int newColor ){
        
        //left,right, up, down 
        
        vector<int> dRow = {0, 0 , -1 , 1 };
        vector<int> dCol = {-1,1 , 0 , 0 };
        
        queue<pair<int,int>> q;
        q.push({sRow, sCol});
        visited[sRow][sCol]=true;
        
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            image[r][c] = newColor;
            
            //check for the safe nbrs
            for(int k=0;k<4;k++){
                int newRow= r + dRow[k];
                int newCol = c + dCol[k];
                if(isSafe(image,visited,newRow, newCol, oldColor)){
                    visited[newRow][newCol]=true;
                    q.push({newRow, newCol});
                }
            }
        }
        return;
    }
    
  public:
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        
        int rowSize = image.size(), colSize= image[0].size();
        
        //visited array 
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
        int oldColor = image[sr][sc];
        
        bfs(image,visited,sr,sc,oldColor,newColor);
        
        return image;
        
    }
};