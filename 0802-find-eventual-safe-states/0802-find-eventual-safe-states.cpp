class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n, 0);
        vector<vector<int>> parents(n);
        queue<int> q;

        for (int node = 0; node < n; node++) {
            outdegree[node] = graph[node].size();
            if (outdegree[node] == 0) {
                q.push(node);
            }
            for (int nei : graph[node]) {
                parents[nei].push_back(node);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int parent : parents[node]) {
                outdegree[parent]--;
                if (outdegree[parent] == 0) {
                    q.push(parent);
                }
            }
        }

        vector<int> res;
        for (int node = 0; node < n; node++) {
            if (outdegree[node] <= 0) {
                res.push_back(node);
            }
        }
        return res;
    }
};