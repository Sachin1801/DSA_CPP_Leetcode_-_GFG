''' 
class Node:

    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None 
'''

from collections import deque

class Solution:
    def leftView(self, root):
        # code here
        
        if root is None:
            return []
            
        if not root.left and not root.right:
            return [root.data]
            
        
        q = deque()
        q.append(root)      # [1] 
        
        
        ans = []  # [1]
        
        # size = 1
        # node = 1
        
        while q:
            
            node = q[0]
            ans.append(node.data)
            size = len(q)
            
            for i in range(size):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                    
                if node.right:
                    q.append(node.right)
                
            
            
        return ans
        