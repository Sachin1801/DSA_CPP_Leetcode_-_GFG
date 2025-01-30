class Solution 
{
    vector<int> parent , rank;

    int findYourParent(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findYourParent(parent[node]); 
    }

    void unionByRank(int u , int v)
    {
        int pu = findYourParent(u);
        int pv = findYourParent(v);

        if(pu == pv) return;
        else if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if (connections.size() < n - 1) return -1;
        rank.resize(n , 0);
        parent.resize(n);
        for(int i = 0 ; i < n ;i++) parent[i] = i;
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            unionByRank(u , v);
        }

        int count = 0;

        for(int i = 0 ; i < n ;i++)
        {
            if(parent[i] == i) count++;
        }

        return count - 1;
    }
};