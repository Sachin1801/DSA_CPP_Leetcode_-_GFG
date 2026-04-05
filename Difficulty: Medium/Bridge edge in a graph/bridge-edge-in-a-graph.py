from collections import defaultdict

class Solution:
    
    timer = 1
    
    def dfs(self, src, parent, adj, vis, tin, low, bridges):
        vis[src] = True
        tin[src] = Solution.timer
        low[src] = Solution.timer
        Solution.timer +=1
        
        for nbr in adj[src]:
            if nbr == parent:
                continue
            if not vis[nbr]:
                self.dfs(nbr, src, adj, vis, tin,low, bridges)
                low[src] = min(low[src], low[nbr])
                if low[nbr] > tin[src]:
                    bridges.add((src,nbr))
                    
            else :
                # check if we can update the low
                low[src] = min(low[nbr], low[src])
                
        return bridges
        
    
    def isBridge(self, V, edges, c, d):
        # code here 
        
        adj = defaultdict(list)
        
        # form the adj list
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        vis = [False] * V
        tin = [0] * V
        low = [0] * V
        
        bridges = set()
        
        for i in range(V):
            if not vis[i]:
                bridges = self.dfs(i,-1, adj, vis, tin, low, bridges)
        
        
        if (c,d) in bridges or (d,c) in bridges:
            return True
        return False
        