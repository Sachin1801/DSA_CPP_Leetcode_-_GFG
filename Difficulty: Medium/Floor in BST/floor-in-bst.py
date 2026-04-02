'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
class Solution:
    def findFloor(self, root, x):
        #code here 
        if not root:
            return -1
        
        if root.data == x:
            return x
        
        ans = -1
        node = root
        
        while node:
            if node.data == x:
                return x
            elif node.data > x:
                node = node.left
            else:
                ans = node.data
                node = node.right
        
        return ans
