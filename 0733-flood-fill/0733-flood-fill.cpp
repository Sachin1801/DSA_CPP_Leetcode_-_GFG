class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int stcolor = image[sr][sc];
        if (stcolor == color) return image;
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            auto front = q.front();
            int i = front.first;
            int j = front.second;
            q.pop();
            if(i-1>=0 && image[i-1][j]==stcolor){
                q.push({i-1,j});
                image[i-1][j]=color;
            }
            if(i+1<image.size() && image[i+1][j]==stcolor){
                q.push({i+1,j});
                image[i+1][j]=color;
            }
            if(j-1>=0 && image[i][j-1]==stcolor){
                q.push({i,j-1});
                image[i][j-1]=color;
            }
            if(j+1<image[0].size() && image[i][j+1]==stcolor){
                q.push({i,j+1});
                image[i][j+1]=color;
            }
        }
        return image;
    }
};