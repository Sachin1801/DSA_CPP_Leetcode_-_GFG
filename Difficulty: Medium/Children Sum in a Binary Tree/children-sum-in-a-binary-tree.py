'''
# Node Class:
class Node:
    def init(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def isSumProperty(self, root):
        # code here
        if not root:
            return True
        
        if not root.left and not root.right:
            return True
        
        left = root.left
        right = root.right
        left_val = left.data if left else 0
        right_val = right.data if right else 0
        
        if left_val + right_val != root.data:
            return False
        
        return (self.isSumProperty(root.left) and self.isSumProperty(root.right))