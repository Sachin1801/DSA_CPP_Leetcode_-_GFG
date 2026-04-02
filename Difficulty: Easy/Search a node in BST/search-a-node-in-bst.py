'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def search(self, root, key):
        # code here
        if not root:
            return False
        
        node = root
        if node.data == key:
            return True
        
        while node:
            if node.data == key:
                return True
            elif node.data < key:
                node = node.right
            else:
                node = node.left
        
        return False