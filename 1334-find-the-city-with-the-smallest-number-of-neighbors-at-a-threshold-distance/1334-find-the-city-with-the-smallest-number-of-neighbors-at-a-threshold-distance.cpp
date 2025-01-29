#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create adjacency list
        vector<vector<pair<int, int>>> Adj(n);
        for (auto& edge : edges) {
            Adj[edge[0]].push_back({edge[1], edge[2]});
            Adj[edge[1]].push_back({edge[0], edge[2]});
        }

        auto dijkstra = [&](int src) {
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.push({0, src}); // {distance, node}

            while (!pq.empty()) {
                auto [currDist, currNode] = pq.top();
                pq.pop();

                if (currDist > dist[currNode]) continue;

                for (auto& [neighbor, weight] : Adj[currNode]) {
                    if (dist[currNode] + weight < dist[neighbor]) {
                        dist[neighbor] = dist[currNode] + weight;
                        pq.push({dist[neighbor], neighbor});
                    }
                }
            }
            return dist;
        };

        // Find the city with the smallest number of neighbors within the distance threshold
        int resultCity = -1, minNeighborCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> dist = dijkstra(i);
            int neighborCount = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && dist[j] <= distanceThreshold) {
                    neighborCount++;
                }
            }

            // Update the result based on the problem statement
            if (neighborCount < minNeighborCount || 
                (neighborCount == minNeighborCount && i > resultCity)) {
                minNeighborCount = neighborCount;
                resultCity = i;
            }
        }

        return resultCity;
    }
};
