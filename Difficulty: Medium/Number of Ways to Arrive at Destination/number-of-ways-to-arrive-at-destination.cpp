//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<long long> ways(n, 0); // Use long long to avoid overflow
        vector<long long> dist(n, LLONG_MAX); // Use long long for distances
        vector<vector<pair<int, int>>> Adj(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        // Build adjacency list
        for (auto road : roads) {
            Adj[road[0]].push_back({road[1], road[2]});
            Adj[road[1]].push_back({road[0], road[2]});
        }

        // Initialize priority queue and distance/ways arrays
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto top = pq.top();
            long long currdst = top.first;
            int currnode = top.second;
            pq.pop();

            // If the current distance is greater than the known distance, skip
            if (currdst > dist[currnode]) continue;

            for (auto nbr : Adj[currnode]) {
                int node = nbr.first;
                long long wt = nbr.second;

                if (dist[node] > dist[currnode] + wt) {
                    dist[node] = dist[currnode] + wt;
                    pq.push({dist[node], node});
                    ways[node] = ways[currnode] % MOD;
                } else if (dist[node] == dist[currnode] + wt) {
                    ways[node] = (ways[node] + ways[currnode]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends