class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: Build adjacency list
        unordered_map<int, vector<pair<int, int>>> Adj;
        for (auto& flight : flights) {
            int sr = flight[0];
            int dest = flight[1];
            int pr = flight[2];
            Adj[sr].push_back({dest, pr}); // Add edge
        }

        // Step 2: Min-heap to store {price, current node, steps}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0}); // {price, node, steps}

        // Step 3: Distance array to prune unnecessary paths
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        // Step 4: Perform BFS with priority queue
        while (!pq.empty()) {
            auto [price, node, steps] = pq.top();
            pq.pop();

            // If destination is reached
            if (node == dst) return price;

            // If stops exceeded, continue
            if (steps > k) continue;

            // Explore neighbors
            for (auto& [nbr, pr] : Adj[node]) {
                int newPrice = price + pr;

                // Only push to the queue if this path is cheaper
                if (newPrice < dist[nbr][steps + 1]) {
                    dist[nbr][steps + 1] = newPrice;
                    pq.push({newPrice, nbr, steps + 1});
                }
            }
        }

        // If no valid path found
        return -1;
    }
};
