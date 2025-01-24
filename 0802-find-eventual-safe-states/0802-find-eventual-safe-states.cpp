class Solution {
    vector<int> safe;

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        safe.assign(n, -1);
        for (int node = 0; node < n; node++) {
            if (dfs(graph, node)) {
                res.push_back(node);
            }
        }
        return res;
    }

private:
    bool dfs(vector<vector<int>>& graph, int node) {
        if (safe[node] != -1) {
            return safe[node];
        }
        safe[node] = 0;
        for (int nei : graph[node]) {
            if (!dfs(graph, nei)) {
                return false;
            }
        }
        safe[node] = 1;
        return true;
    }
};