
from queue import Queue

class Solution:
	def orangesRot(self, mat):
		# code here
		
		time = -1
		dir = [(-1,0),(1,0),(0,-1),(0,1)]
		n, m = len(mat), len(mat[0])
		q = Queue()
		fresh = 0
		
		for i,r in enumerate(mat):
		    for j,val in enumerate(r):
		        if val == 2:
		            q.put((i,j))
		        elif val == 1:
		            fresh +=1 
		            
		if fresh == 0:
		    return 0
		     
		while not q.empty():
		    size = q.qsize()
		    while size > 0:
		        curr_i, curr_j = q.get()
		        for direction in dir:
		            
		            next_i = direction[0]
		            next_j = direction[1]
		             
		            new_i = curr_i + next_i
		            new_j = curr_j + next_j
		             
		            # check if the new index is inbound and is a 1
		            if new_i < n and new_i >=0 and new_j >=0 and new_j < m and mat[new_i][new_j] == 1:
		                mat[new_i][new_j] = 2
		                fresh -=1
		                q.put((new_i, new_j))
		               
                size -=1
		    time += 1
		
		  
	    return time if fresh == 0 else -1
		     
		 
		        