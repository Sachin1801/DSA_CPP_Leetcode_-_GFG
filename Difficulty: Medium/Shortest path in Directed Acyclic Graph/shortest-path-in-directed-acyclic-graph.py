#User function Template for python3

from typing import List
from collections import defaultdict, deque


class Solution:
    
    def findTopoOrder(self, V, adj, indegree):
        
        q = deque()
        
        for i in range(V):
            if indegree[i] == 0:
                q.append(i)
        
        st = []
        while q:
            src = q.popleft()
            st.append(src)
            for v,cost in adj[src]:
                indegree[v] -=1
                if indegree[v] == 0:
                    q.append(v)
                    
        
        if len(st) != V:
            return []
        return st
        
    
    def shortestPath(self, V: int, E: int,
                     edges: List[List[int]]) -> List[int]:
        
        adj = defaultdict(list)
        indegree = [0] * V
        
        for edge in edges:
            u = edge[0]
            v = edge[1]
            wt = edge[2]
            
            adj[u].append((v,wt))
            indegree[v] +=1
        
        st = self.findTopoOrder(V,adj,indegree)
        if not st:
            return [-1] * V
            
        # now we have the topo sort in st
        dist = [float('inf')] * V
        dist[0] = 0
        
        for top in st:
            
            #skip the non reachable ones
            if dist[top] == float('inf'):
                continue
            
            for v,cost in adj[top]:
                if dist[top] + cost < dist[v]:
                    dist[v] = dist[top] + cost
        
        for i in range(V):
            if dist[i] == float('inf'):
                dist[i] = -1
         
        return dist
                