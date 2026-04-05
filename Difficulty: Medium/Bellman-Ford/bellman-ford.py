#User function Template for python3

from collections import defaultdict

class Solution:
    def bellmanFord(self, V, edges, src):
        #code here
        
        # to check for negative weight cycle
        
        # Step 1 : make the adj list 
        # Track the distances of all from the src
        
        adj = defaultdict(list)
        
        for edge in edges:
            u = edge[0]
            v = edge[1]
            wt = edge[2]
            
            adj[u].append((v,wt))
            
        dist = [int(1e8)] * V
        dist[src] = 0
        
        # we have to relax the graph V-1 times
        for i in range(V-1):
            for edge in edges:
                u = edge[0]
                v = edge[1]
                wt = edge[2]
                
                if dist[u] != 1e8 and dist[v] > wt + dist[u]:
                    dist[v] = dist[u] + wt
        
        
        # now we have relaxed the graph v-1 times
        # do one more iteration : if any edge relaxes again -> we have a negative cycle
        for edge in edges:
                u = edge[0]
                v = edge[1]
                wt = edge[2]
                
                if dist[u] != 1e8 and dist[v] > wt + dist[u]:
                    return [-1]
                    
        return dist