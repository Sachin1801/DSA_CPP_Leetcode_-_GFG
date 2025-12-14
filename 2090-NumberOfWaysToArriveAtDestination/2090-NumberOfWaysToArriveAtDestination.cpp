// Last updated: 12/14/2025, 4:17:01 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1000000007;

        // Adjacency list: for each node, store {neighbor, weight}
        vector<vector<pair<int,int>>> graph(n);
        for (auto &r : roads) {
            int u = r[0], v = r[1], w = r[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // dist[i]: shortest distance from 0 to i
        // ways[i]: number of shortest paths from 0 to i
        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        // Min-heap of {distance, node}
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            // If this distance is stale, ignore
            if (currDist > dist[u]) continue;

            // Relax edges
            for (auto &[v, w] : graph[u]) {
                long long newDist = dist[u] + w;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u]; // inherit the number of ways
                    pq.push({dist[v], v});
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};
