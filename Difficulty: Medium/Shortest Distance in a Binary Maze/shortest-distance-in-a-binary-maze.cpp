//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

private:
    bool check(int newrow, int newcol ,int row, int col){
        return (newrow < row and newrow >=0 and newcol<col and newcol >=0);
    }

  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int rowsize = grid.size();
        int colsize = grid[0].size();
        vector<vector<int>> distance(rowsize,vector<int>(colsize,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        //right, left, down, up
        vector<pair<int,int>> directions={{0,+1},{0,-1},{+1,0},{-1,0}};
        q.push({0,source});
        distance[source.first][source.second]=0;
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
                if((check(newrow,newcol,rowsize,colsize)==true) and (grid[newrow][newcol]==1) and (distance[newrow][newcol]> dist+1)){
                    distance[newrow][newcol] = dist + 1;
                    q.push({dist+1,{newrow,newcol}});
                }
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends