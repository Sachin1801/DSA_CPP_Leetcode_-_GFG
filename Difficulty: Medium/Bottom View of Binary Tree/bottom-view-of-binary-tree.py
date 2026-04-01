'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

from collections import deque 

class Solution:
    def bottomView(self, root):
        # code here
        
        if root is None:
            return []
        
        def findLeft(node):
            if not node:
                return 0
            
            left = 0
            while node.left is not None:
                node = node.left
                left += 1
                
            return left
        
        def findRight(node):
            if not node:
                return 0
            
            right = 0
            while node.right:
                node = node.right
                right +=1 
                
            
            return right
        
        node = root
            
        left = findLeft(node)
        node = root
        right = findRight(node)
        
        tot_col = left + right + 1 
        
        d = {} 
        q = deque([(root,0)])
        
        while q:
            node, col = q.popleft()
            
            d[col] = node.data
            
            if node.left:
                q.append((node.left, col-1))
                
            if node.right:
                q.append((node.right, col+1))
        
        return [ d[k] for k in sorted(d) ]
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        