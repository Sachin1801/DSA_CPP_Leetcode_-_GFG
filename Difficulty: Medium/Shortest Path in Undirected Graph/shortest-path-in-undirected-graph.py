
from collections import defaultdict, deque

class Solution:
    def shortestPath(self, V, edges, src):
        # code here
        dist = [float('inf')] * V
        dist[src] = 0;
        
        #edge case
        if not edges:
            for i in range(1,V):
                dist[i] = -1
            return dist
            
        # Step 1 : form the adj list
        adj = defaultdict(list)
        for edge in edges:
            u = edge[0]
            v = edge[1]
            #add both edges
            adj[u].append(v)
            adj[v].append(u)
            
        # src to start from 
        q = deque([src])
        while q:
            u = q.popleft()
            curr_dist = dist[u]
            
            for nbr in adj[u]:
                if dist[nbr] == float('inf'):
                    dist[nbr] = curr_dist + 1
                    q.append(nbr)
        
        for i in range(V):
            if dist[i] == float('inf'):
                dist[i] = -1
            
        return dist
        
