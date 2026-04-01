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
        if not root.left and not root.right:
            return 1
        
        total = 1
        q = deque({root})
        
        while q:
            node = q.popleft()
            
            # if we have both children : just push in queue
            #     and total+=2
            if node.left and node.right:
                q.append(node.left)
                q.append(node.right)
                total += 2
            elif node.left and not node.right:
                total+=1
                break
            else:
                break
            # if we have only one children 
                # add total +=1 and break
            
            # if we have no children
                # break
        
        return total
                