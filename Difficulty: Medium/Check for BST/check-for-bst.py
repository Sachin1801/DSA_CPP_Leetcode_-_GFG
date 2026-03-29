'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    # @staticmethod
    
    def isBstUtil( self,root, min_val, max_val):
        # Base case
        if root is None:
            return True
            
        # Check if the current node data is not in the range
        curr_node = root.data
        if curr_node < min_val or curr_node > max_val:
            return False
        
        left = self.isBstUtil(root.left, min_val,root.data-1)
        right = self.isBstUtil( root.right, root.data+1, max_val)
        
        if not left or not right:
            return False
        
        return True
    
    def isBST(self, root):
        #code here
        return self.isBstUtil(root, float('-inf'), float('inf'))