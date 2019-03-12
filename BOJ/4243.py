# https://www.acmicpc.net/problem/4243
# recursion
import sys
input = sys.stdin.readline

def dis(start, end):
	d = 0
	for i in range(start, end):
		d += dist[i]

	return d	

def cover(i, j, d):
	"""
	return the minimum wating time left when you already have covered i~j.
	"""
	if i == 0 and j == n-1:
		return 0

	if memo[i][j][d] != -1:
		return memo[i][j][d]

	if d == 0:
		curr = i
	else:
		curr = j

	move_left = 1e18	
	move_right = 1e18
	if i > 0:
		move_left = cover(i-1, j, 0) + (n - (j-i + 1)) * dis(i-1, curr)
	if j < n - 1:	
		move_right = cover(i, j+1, 1) + (n - (j-i + 1)) * dis(curr, j+1)
	
	# the reason why multiply dis with (n - (j-i + 1))
	# (n - (j-i + 1)) means left stations to go.
	# The waiting time is accumulative so, dis added every afterwards movement	
	
	ans = min(move_left, move_right)
	memo[i][j][d] = ans

	return ans

case = int(input())

while case:
	case -= 1
	n = int(input())
	start = int(input())

	dist = []
	for _ in range(n-1):
		dist.append(int(input()))

	memo = [[[-1, -1] for _ in range(n)] for _ in range(n)]
	print(cover(start-1, start-1, 0))

##############################################################################################################
##############################################################################################################
# without recursion
import sys
input = sys.stdin.readline

def dis(start, end):
	d = 0
	for i in range(start-1, end-1):
		d += dist[i]

	return d	

case = int(input())

while case:
	case -= 1
	n = int(input())
	start = int(input())

	dist = []
	for _ in range(n-1):
		dist.append(int(input()))

	memo = [[[0, 0] for _ in range(n+1)] for _ in range(n+1)]

	for i in range(n+1):
		for j in range(n+1):
			memo[i][j][0] = 1e18
			memo[i][j][1] = 1e18

	memo[start][start] = [0,0]
	for i in range(start,0, -1):
		for j in range(start, n+1, 1):
			if i == j:
				continue
			mul = n - (j-i)	
			memo[i][j][0] = min(memo[i+1][j][0] + mul * dis(i,i+1), memo[i+1][j][1] + mul * dis(i,j))
			memo[i][j][1] = min(memo[i][j-1][0] + mul * dis(i,j), memo[i][j-1][1] + mul*dis(j-1, j))
	
	print(min(memo[1][n]))