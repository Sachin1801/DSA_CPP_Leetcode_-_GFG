from collections import defaultdict
import heapq

class Solution:
    def spanningTree(self, V, edges):
        # code here
        
        adj = defaultdict(list)
        
        for edge in edges:
            u = edge[0]
            v = edge[1]
            wt = edge[2]
            
            adj[u].append((v,wt))
            adj[v].append((u,wt))
        
        # get the minheap
        min_heap = []
        heapq.heappush(min_heap,(0,edges[0][0]))
        
        # vistied array to mark the ones visited in mst
        visited = [False] * V
        mst_wt = 0
        
        while min_heap:
            
            wt, src = heapq.heappop(min_heap)
            if visited[src]:
                continue
            
            visited[src] = True
            mst_wt += wt
            
            # visit all nbrs
            for nbr,cost in adj[src]:
                if not visited[nbr]:
                    heapq.heappush(min_heap,(cost,nbr))
        
        return mst_wt