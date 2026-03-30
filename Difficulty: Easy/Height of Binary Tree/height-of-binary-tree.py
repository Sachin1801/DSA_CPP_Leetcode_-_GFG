'''
# Node Class:
class Node:
    def _init_(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def height(self, root):
        # code here
        
        def max_height(root):
            if root is None:
                return 0
            if root.left is None and root.right is None:
                return 0
            
            return 1 + max(max_height(root.left), max_height(root.right))
            
        
        return max_height(root)