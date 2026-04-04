#User function Template for python3

import sys
# from collections import set
from typing import List
sys.setrecursionlimit(10**8)
class Solution:
    
    def findIslands(self, grid, i, j, n, m, li):
        if i < 0 or i >= n or j < 0 or j >=m or grid[i][j] == 0:
            return
        
        grid[i][j] = 0
        li.append([i,j])
        self.findIslands(grid, i,j+1,n,m, li)
        self.findIslands(grid, i+1, j, n,m,li)
        self.findIslands(grid, i-1, j, n,m,li)
        self.findIslands(grid, i, j-1, n,m,li)
        
    
    def normalise(self, curr_li):
        
        curr_li.sort()
        base_i, base_j = curr_li[0]
        norm = []
        for (x,y) in curr_li:
            norm.append((x-base_i, y-base_j))
        
        norm.sort()
        return tuple(norm)

    
    
    def countDistinctIslands(self, grid : List[List[int]]) -> int:
        # code here
        if not grid:
            return 0
        
        n, m = len(grid), len(grid[0])
        unique = set()
        # iterate over the grid to find the index for land
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    curr_li = []
                    self.findIslands(grid, i, j, n, m, curr_li)
                    
                    if curr_li:
                        shape = self.normalise(curr_li)
                        unique.add(shape)
        
        return len(unique)
        