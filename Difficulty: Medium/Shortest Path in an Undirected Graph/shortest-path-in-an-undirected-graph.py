

#User function Template for python3
import heapq
from typing import List
from collections import defaultdict

class Solution:
    def shortestPath(self,n:int, m:int, edges:List[List[int]] )->List[int]:
        # code here
        if not edges:
            return -1
        
        adj = defaultdict(list)
        for edge in edges:
            u = edge[0]
            v = edge[1]
            wt = edge[2]
            
            adj[u].append((v,wt))
            adj[v].append((u,wt))
            
        # heapq.heapify(min_heap)
        
        distances = [float('inf')] * (n+1)
        min_heap = [] # each element is -> (node,dist)
        parent = [-1] * (n+1)
        
        heapq.heappush(min_heap,(0,1))
        distances[1] = 0    # marking the distance of V=1 as 0
        parent[1] = 1
        
        while min_heap:
            dist, src = heapq.heappop(min_heap)
            
            if dist > distances[src]:
                continue
            
            for nbr, cost in adj[src]:
                if distances[nbr] > dist + cost:
                    distances[nbr] = dist + cost
                    parent[nbr] = src
                    heapq.heappush(min_heap,(distances[nbr], nbr))
        
        if distances[n] == float('inf'):
            return [-1]
            
            
        path = []
        curr = n
        
        
        while curr != parent[curr]:
            path.append(curr)
            curr = parent[curr]
        
        path.append(1)
        path.reverse()
        
        return [distances[n]] + path
        