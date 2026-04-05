#User function Template for python3

import sys
sys.setrecursionlimit(10**6)

class Solution:
    
    timer = 0
    
    def dfs(self, src, parent, adj, vis, tin, low, in_ap):
        vis[src] = True
        tin[src] = Solution.timer
        low[src] = Solution.timer
        Solution.timer +=1
        
        child = 0
        for nbr in adj[src]:
            if nbr == parent:
                continue
            if not vis[nbr]:
                child +=1
                self.dfs(nbr, src, adj, vis, tin,low, in_ap)
                low[src] = min(low[src], low[nbr])
                # if parent == -1 and len(adj[src]) == 1:
                #     continue
                if low[nbr] >= tin[src] and parent != -1:
                    in_ap[src] = True
                    
            else :
                # check if we can update the low
                low[src] = min(tin[nbr], low[src])
                
        if child > 1 and parent == -1:
            in_ap[src] = True
    
    #Function to return Breadth First Traversal of given graph.
    def articulationPoints(self, V, adj):
        # code here
        
        tin = [-1] * V
        low = [-1] * V
        visited = [False] * V
        is_ap = [False] * V 
        
        for i in range(V):
            if not visited[i]:
                self.dfs(i, -1, adj, visited, tin, low, is_ap)
                
        ans = [i for i in range(V) if is_ap[i]]
        
        if not ans:
            return [-1]
            
        return ans
        
        