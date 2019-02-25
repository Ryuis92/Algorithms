# https://www.acmicpc.net/problem/2252
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
class Problem:
	def __init__(self):
		self.n, self.m = map(int, input().split())
		self.adj = [[] for _ in range(self.n+1)]
		self.bitmap = [False for _ in range(self.n+1)]
		
		for _ in range(self.m):
			first, second = map(int, input().split())
			self.adj[second].append(first)

	def topo(self, start):
		if self.bitmap[start]:
			return

		self.bitmap[start] = True
		for before in self.adj[start]:
			if not self.bitmap[before]:
				self.topo(before)
		print(start, end=" ")
	
	def main(self):
		for i in range(1, self.n+1):
			self.topo(i)

a = Problem()
a.main()					