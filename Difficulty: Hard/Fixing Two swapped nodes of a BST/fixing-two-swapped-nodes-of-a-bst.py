#User function Template for python3

'''
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
        
'''

class Solution:
    def correctBST(self, root):
        # code here
        if not root:
            return root
        
        
        def Inorder(root):
            inorder = []
            curr = root
            while curr:
                if not curr.left:
                    inorder.append(curr)
                    curr = curr.right
                else:
                    prev = curr.left
                    while prev.right and prev.right !=curr:
                        prev = prev.right
                        
                    if not prev.right:
                        prev.right = curr
                        curr = curr.left
                    else:
                        prev.right = None
                        inorder.append(curr)
                        curr = curr.right
            
            return inorder
            
        inorder = Inorder(root)
        
        # find the violations
        prev = None
        
        n = len(inorder)
        violations = []
        for i,node in enumerate(inorder):
            if i == 0:
                prev = node
            else:
                if node.data < prev.data:
                    violations.append((prev,node))
                
                prev = node 
                
        if len(violations) == 1:
            node_1, node_2 = violations[0]
            node_1.data, node_2.data = node_2.data, node_1.data
        else:
            node_1, node_2 = violations[0]
            node_3, node_4 = violations[1]
            node_1.data, node_4.data = node_4.data, node_1.data
            
        return root
        