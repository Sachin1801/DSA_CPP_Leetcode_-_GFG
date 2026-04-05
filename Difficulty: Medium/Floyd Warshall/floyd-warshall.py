#User function template for Python

class Solution:
	def floydWarshall(self, dist):
		#Code here
		
		V = len(dist)
		
		for i in range(V):
		    for j in range(V):
		        for k in range(V):
		           if dist[j][i] == int(1e8) or dist[i][k] == 1e8:
		               continue
		           
		           dist[j][k]= min(dist[j][k],dist[j][i]+ dist[i][k])
		           
		return 