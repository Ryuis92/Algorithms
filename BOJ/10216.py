# https://www.acmicpc.net/problem/10216
import sys
input = sys.stdin.readline
x = 0
y = 1
r = 2
class Problem:
	def __init__(self):
		self.n = int(input())
		self.adj = [[] for _ in range(self.n)]
		self.bitmap = [False for _ in range(self.n)]
		arr = []
		for _ in range(self.n):
			arr.append(list(map(int, input().split())))

		for i in range(len(arr)):
			for j in range(i+1,len(arr)):
				if (arr[i][x] - arr[j][x])**2 + (arr[i][y] - arr[j][y])**2 <= (arr[i][r] + arr[j][r])**2:
					self.adj[i].append(j)
					self.adj[j].append(i)

	def dfs(self, root):
		s = [root]
		self.bitmap[root] = True

		while len(s):
			p = s.pop()
			for node in self.adj[p]:
				if not self.bitmap[node]:
					self.bitmap[node] = True
					s.append(node)

		return 1	

	def main(self):
		res = 0
		for i in range(len(self.adj)):
			if not self.bitmap[i]:
				res += self.dfs(i)

		print(res)		

case = int(input())
while case:
	case -=1
	a = Problem()
	a.main()		