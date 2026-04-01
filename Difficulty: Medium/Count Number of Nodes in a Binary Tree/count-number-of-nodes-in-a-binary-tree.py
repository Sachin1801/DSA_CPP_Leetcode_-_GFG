#User function Template for python3

'''
# Node Class:
class Node:
    def init(self, val):
        self.data = val
        self.left = None
        self.right = None
'''
from collections import deque

class Solution:
    def countNodes(self, root):
        #code here
        if not root:
            return 0
        
        
        left_h, right_h = 0,0
        l, r = root, root
        
        while l:
            left_h +=1 
            l = l.left
        while r:
            right_h += 1
            r = r.right
        
        if left_h == right_h:
            return (1 << left_h) - 1  # 2^h-1
            
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)