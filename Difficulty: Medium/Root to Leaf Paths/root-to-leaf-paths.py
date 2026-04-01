from typing import Optional
from collections import deque

from typing import List

"""

definition of binary tree node.
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
"""

class Solution:
    
    def findAllPaths(self, node, curr_path, ans):
        # base case
        if not node:
            return
        
        curr_path.append(node.data)
        
        # at the leaf node
        # push the current path
        if not node.left and not node.right:
            ans.append(curr_path[:])
            curr_path.pop()
            return
        
        else:
            self.findAllPaths(node.left, curr_path,ans)
            self.findAllPaths(node.right, curr_path,ans)
        
        curr_path.pop()
    
    def Paths(self, root):
        # code here
        if not root:
            return []
            
        ans= [] 
        
        curr_path = []
        
        self.findAllPaths(root, curr_path, ans)
        return ans