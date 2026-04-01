'''
class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None
'''

class Solution:
    
    def lca(self, root, n1, n2):
        # code here
        if not root:
            return None
            
        if root.data == n1 or root.data == n2:
            return root
            
        left = self.lca(root.left, n1, n2)
        right = self.lca(root.right, n1, n2)
        
        if left and right:
            return root
        
        return left if left else right
        

