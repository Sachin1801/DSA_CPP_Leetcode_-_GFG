'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    
    def solve(self, root):
        if root is None:
            return [0,True]
            
        if root.left is None and root.right is None:
            return [1,True]
            
        left_h = self.solve(root.left)
        if left_h[1] == False:
            return left_h
            
        right_h = self.solve(root.right)
        if right_h[1] == False:
            return right_h
        
        net_h = 1 + max(left_h[0], right_h[0])
        if abs(left_h[0] - right_h[0]) <= 1:
            return [net_h, True]
            
        return [net_h, False]
    
    def isBalanced(self, root):
        # code here
        
        is_balanced = self.solve(root)
        if is_balanced[1] == True:
            return True
        return False