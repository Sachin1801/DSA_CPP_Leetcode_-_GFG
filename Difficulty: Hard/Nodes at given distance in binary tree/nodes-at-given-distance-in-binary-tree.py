'''
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''

from collections import defaultdict, deque

class Solution:
    
    def KDistanceNodes(self,root,target,k):
        # code here
        # return the sorted list all nodes at k distance from target
        
        if not root:
            return []
        
        d = defaultdict(list)
        q = deque()
        q.append(root)
        
        target_node = None
        while q:
            node = q.popleft()
            if node.data == target:
                target_node = node
            
            left_child = node.left if node.left else None
            right_child = node.right if node.right else None
            
            if left_child:
                d[node].append(left_child)
                d[left_child].append(node)
                q.append(left_child)
            if right_child:
                d[node].append(right_child)
                d[right_child].append(node)
                q.append(right_child)
            
        # print(d)
        # perform bfs of depth k 
        q.append(target_node)
        # visited dict
        visited = {target_node.data}
        # final ans
        current_level = 0
        
        while current_level < k:
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                # push all its nbrs
                for nbr in d[node]:
                    if nbr.data not in visited:
                        q.append(nbr)
                        visited.add(nbr.data)
            current_level+=1
        
        ans = [node.data for node in q]
        return sorted(ans)
            
            
            
            
            
            
            
            
            
            
            
            
            
        