# https://www.acmicpc.net/problem/1693
# ref : https://blog.encrypted.gg/144
import sys
import math
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

n = int(input())
adj = [[] for i in range(n+1)] #adj[n+1]
color_num = int(math.log2(n)) + 1
dp = [[0 for i in range(color_num+1)] for j in range(n+1)] # dp[n+1][color_num]

for i in range(n-1):
	a, b = map(int, input().split())
	adj[a].append(b)
	adj[b].append(a)

def coloring(root, parent):
	#add color cost i
	for i in range(1, color_num+1):
		dp[root][i] += i

	for child in adj[root]:
		if child == parent:
			continue

		#fill dp table of children	
		coloring(child, root)

		#two index for min, and second min
		min1 = color_num
		min2 = color_num
		for i in range(1, color_num+1):
			if dp[child][i] < dp[child][min2]:
				min2 = i
			if dp[child][min2] < dp[child][min1]:
				min1, min2 = min2, min1
		
		#add minimum cost of child. In case the min index(or color) is same, use second min
		for i in range(1, color_num+1):			
			if i != min1:
				dp[root][i] += dp[child][min1]
			else:
				dp[root][i] += dp[child][min2]	

coloring(1, -1)
print(min(dp[1][1:]))


"""
dp[i][j] denotes that the minimum cost of a tree rooted at i and the color of root i is j.
dp[i][j] = j + minimum total cost of children.

Here the function coloring is filling the dp table.

"""