//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    

private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node]=1;
        for(auto it: adj[node] ){
            if(!vis[it])
                dfs(it,adj,vis);
        }
    }


  public:
    int numProvinces(vector<vector<int>> isConnected, int V) {
        // code here
        vector<vector<int>> adjls(V, vector<int>(V));

        //common way to convert adjacency matrix into adj list
        for(int i=0;i<V;i++){
            for(int j=0;j<V; j++){
                if(isConnected[i][j] ==1 && i!= j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0); //visited array
        int cnt=0; 
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends