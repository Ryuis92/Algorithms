# https://www.acmicpc.net/problem/10451
import sys
input = sys.stdin.readline

def dfs(root, edge, bitmap):
	s = [root]
	
	while len(s):
		p = s.pop()
		bitmap[p] = True
		
		next_node = edge[p]
		if next_node != root:
			s.append(next_node)
		
case = int(input())

while case:
	case -=1
	n = int(input())
	edge = [0] + list(map(int, input().split()))
	bitmap = [False for _ in range(n+1)]
	count = 0
	for i in range(1, n+1):
		if not bitmap[i]:
			count += 1
			dfs(i, edge, bitmap)
	print(count)		 
