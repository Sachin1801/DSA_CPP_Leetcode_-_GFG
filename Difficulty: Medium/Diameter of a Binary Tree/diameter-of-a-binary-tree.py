'''
# Tree Node
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    
    def solve(self, root):
        if root is None:
            return [0,0]
        
        # if it is a leaf node
        if root.left is None and root.right is None:
            return [0,1]
        
        left_h = self.solve(root.left)
        right_h = self.solve(root.right)
        
        # Get the previous max Diamter 
        maxD = max(left_h[0],right_h[0])
        
        # Compute the max Diamter till now with the diamter at the current node
        maxD = max(maxD, left_h[1] + right_h[1])
        
        # Caculate the max abs height on left / right on the node 
        h = 1 + max(left_h[1], right_h[1])
        
        return [maxD, h]
    
    def diameter(self, root):
        # code here
        # pair : maxDiameter, height
        max_height_pair = self.solve(root)
        return max_height_pair[0]
        