'''
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    
    def __init__(self):
        self.maxi = float('-inf')
    
    def solve(self,root):
        if root is None:
            return 0
            
        left_sum = self.solve(root.left)
        if left_sum < 0:
            left_sum = 0
        right_sum = self.solve(root.right)
        if right_sum < 0:
            right_sum = 0
            
        self.maxi = max(self.maxi, left_sum + right_sum + root.data)
        return root.data + max(0,max(left_sum, right_sum))
    
    
    def findMaxSum(self, root): 
        if root is None:
            return 0
        self.solve(root)
        return self.maxi
        