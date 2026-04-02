'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def insert(self, root, key):
        # code here
        if not root:
            return Node(key)
        
        node = root
        while node:
            if node.data < key:
                if node.right:
                    node = node.right
                else:
                    node.right = Node(key)
                    break
            else:
                if node.left:
                    node = node.left
                else:
                    node.left = Node(key)
                    break
                
            
        return root        