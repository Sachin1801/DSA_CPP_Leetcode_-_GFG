class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create adjacency list
        unordered_map<int, vector<pair<int, int>>> adjacency;
        for (const auto& time : times) {
            int src = time[0];
            int dst = time[1];
            int t = time[2];
            adjacency[src].emplace_back(dst, t);
        }

        // Priority queue for Dijkstra's algorithm (min-heap based on time)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k);
        set<int> visited;
        int delays = 0;

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            // Skip if the node has been visited
            if (visited.count(node)) {
                continue;
            }

            visited.insert(node);
            delays = max(delays, time);
            for (const auto& neighbor : adjacency[node]) {
                int neighborNode = neighbor.first;
                int neighborTime = neighbor.second;
                if (!visited.count(neighborNode)) {
                    pq.emplace(time + neighborTime, neighborNode);
                }
            }
        }

        // Check if all nodes have been visited
        return visited.size() == n ? delays : -1;
    }
};