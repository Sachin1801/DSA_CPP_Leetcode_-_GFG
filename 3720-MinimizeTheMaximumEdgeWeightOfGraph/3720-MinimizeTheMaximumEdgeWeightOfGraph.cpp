// Last updated: 12/14/2025, 4:15:19 PM
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // 1) Gather all distinct weights
        vector<int> weights;
        weights.reserve(edges.size());
        for (auto &e : edges) {
            // e = [A, B, W]
            weights.push_back(e[2]);
        }
        sort(weights.begin(), weights.end());
        weights.erase(unique(weights.begin(), weights.end()), weights.end());

        // We also build adjacency in a moment, but we only
        // construct the reversed graph for each candidate M inside feasibility check.

        // A helper function to check feasibility for a given maxWeight
        auto canDo = [&](int maxW) {
            // Build reversed adjacency for edges with weight <= maxW
            // reversedAdj[u] = list of v such that (v->u) is an original edge with weight <= maxW
            vector<vector<int>> reversedAdj(n);
            reversedAdj.reserve(n);
            for (auto &e : edges) {
                int A = e[0], B = e[1], W = e[2];
                if (W <= maxW) {
                    reversedAdj[B].push_back(A);
                }
            }

            // BFS from node 0 in reversed graph
            vector<bool> visited(n, false);
            vector<int> usedOut(n, 0);   // how many edges we have "used" from each node in the original direction
            queue<int>q;
            visited[0] = true;
            q.push(0);

            int visitedCount = 1;

            while (!q.empty()) {
                int u = q.front(); 
                q.pop();

                // Explore reversed edges u->v
                // which corresponds to v->u in the original graph
                for (int v : reversedAdj[u]) {
                    if (!visited[v]) {
                        // We can only use edge v->u if v has outdegree < threshold
                        if (usedOut[v] < threshold) {
                            usedOut[v]++;
                            visited[v] = true;
                            visitedCount++;
                            q.push(v);
                        }
                    }
                }
            }

            return (visitedCount == n);
        };

        // 2) Binary search (or search) over the sorted distinct weights
        int left = 0, right = (int)weights.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canDo(weights[mid])) {
                ans = weights[mid];
                right = mid - 1;  // try smaller weight
            } else {
                left = mid + 1;   // must allow bigger weight
            }
        }
        return ans;
    }
};