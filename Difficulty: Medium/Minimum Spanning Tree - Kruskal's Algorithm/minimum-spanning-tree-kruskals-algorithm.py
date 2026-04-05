#User function Template for python3
from typing import List

class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n
        
    def find(self, x):
        
        root = x 
        
        if self.parent[root] != root:
            self.parent[x] = self.find(self.parent[root])
            return self.parent[x]
        
        return root
        
    def union(self, x, y):
        ulp_x, ulp_y = self.find(x), self.find(y)
        
        if ulp_x == ulp_y:
            return False
        
        rank_x = self.rank[ulp_x]
        rank_y = self.rank[ulp_y]
        
        if rank_x < rank_y:
            self.parent[ulp_x] = ulp_y
        elif rank_y < rank_x:
            self.parent[ulp_y] = ulp_x
        else:
            self.parent[ulp_y] = ulp_x
            self.rank[ulp_x] +=1
        return True

class Solution:
    def kruskalsMST(self, V: int, edges: List[List[int]]) -> int:
        # code here
        
        edges.sort(key=lambda x: x[2])
        # print(edges)
        
        # form the disjoint set class and make an object of the class 
        d = DisjointSet(V)
        tot_wt = 0
        edges_added = 0
        
        # start parsing the edges one by one
        # if they are not part of the same component
            # add the wt of the edge in the total wt
            # do the path compression to update the ultimate parents
        for edge in edges:
            u = edge[0]
            v = edge[1]
            wt = edge[2]
            
            # check if they are a part of same component or not
            if d.union(u,v):
                edges_added +=1
                tot_wt += wt
                if edges_added == V-1:
                    break
                
        return tot_wt
                