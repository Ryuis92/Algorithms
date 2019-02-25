# https://www.acmicpc.net/problem/1516
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
class Problem:
	def __init__(self):
		self.n = int(input())
		self.adj = [[] for _ in range(self.n+1)]
		self.time = [-1 for _ in range(self.n+1)]
		self.memo = [-1 for _ in range(self.n+1)]
		for i in range(1,self.n+1):
			temp = list(map(int, input().split()))
			self.time[i] = temp[0]
			for j in range(1, len(temp)):
				if temp[j] == -1:
					break
				self.adj[i].append(temp[j])	

	def topo(self, root):
		if self.memo[root] != -1:
			return self.memo[root]

		res = 0
		for before in self.adj[root]:
			res = max(res,self.topo(before))
		res += self.time[root]
		self.memo[root] = res
		
		return res				

	def main(self):
		for i in range(1, self.n+1):
			print(self.topo(i))

a = Problem()
a.main()			
