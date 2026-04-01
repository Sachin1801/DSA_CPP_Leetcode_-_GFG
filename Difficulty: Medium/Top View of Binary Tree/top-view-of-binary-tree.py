'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

from collections import deque

class Solution:
    def topView(self, root):
        # code here
        
        if not root:
            return []
            
        d = {}
        q = deque([(root,0)])
        
        while q:
            node, col = q.popleft()
            
            if col not in d:
                d[col] = node.data
                
            
            if node.left:
                q.append([node.left, col-1])
            if node.right:
                q.append([node.right, col+1])
                
        
        return [d[k] for k in sorted(d)]
        
        