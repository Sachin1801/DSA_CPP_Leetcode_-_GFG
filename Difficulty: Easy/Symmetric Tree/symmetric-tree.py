'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    def isSymmetric(self, root):
        # code here
        
        if root is None:
            return True
            
        if not root.left and not root.right:
            return True
        
        if not root.left or not root.right:
            return False
        
        def treeHeight(node, height):
            while node:
                node = node.left
                height +=1
                
            return height
            
            
        node = root
        height = 0
        height = treeHeight(node, height)
        
        mat = [[] for _ in range(height)]
        mat[0].append(root)
        # q = deque()
        # q.append(root)
        
        for level in range(height):
            # skip the symmetry check for level 0
            # else check for symmetry check on each level
            if level != 0:
                level_size = len(mat[level])
                if level_size % 2 != 0:
                    return False
                
                mid = level_size // 2
                
                current_level = mat[level]
                for i in range(mid):
                    left = current_level[i]
                    right = current_level[level_size - i - 1]
                    
                    left_val = left.data if left else None
                    right_val = right.data if right else None
                    
                    if left_val != right_val:
                        return False
            
            # for all the children of nodes on the current level
            if level < height - 1:
                for node in mat[level]:
                    if node is None:
                        mat[level+1].append(None)
                        mat[level+1].append(None)
                    else:
                        mat[level+1].append(node.left)
                        mat[level+1].append(node.right)
                        
                        
        return True
