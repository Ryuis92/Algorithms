# https://www.acmicpc.net/problem/2606

def dfs(root, adj):
	s = [root]
	bitmap = [False for _ in range(n+1)]
	count = -1
	bitmap[root] = True
	while len(s):
		p = s.pop()
		count +=1

		for node in adj[p]:
			if not bitmap[node]:
				s.append(node)
				bitmap[node] = True
	return count			


n = int(input())
line = int(input())
adj = [[] for _ in range(n+1)]

for _ in range(line):
	a, b = map(int, input().split())
	adj[a].append(b)
	adj[b].append(a)

print(dfs(1, adj))