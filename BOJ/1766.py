#https://www.acmicpc.net/problem/1766
import sys
from queue import PriorityQueue
input = sys.stdin.readline

class Problem:
	def __init__(self):
		self.n, self.m = map(int, input().split())
		self.adj = [[] for _ in range(self.n+1)]
		self.inedge = [0 for _ in range(self.n+1)]
		for _ in range(self.m):
			first, second = map(int, input().split())
			self.adj[first].append(second)
			self.inedge[second] += 1

	def topo(self):
		curr = -1
		pq = PriorityQueue()
		for i in range(1, self.n+1):
			if self.inedge[i] == 0:
				pq.put(i)

		for _ in range(self.n):
			curr = pq.get()
			print(curr, end=" ")
			for after in self.adj[curr]:
				self.inedge[after] -= 1
				if self.inedge[after] == 0:
					pq.put(after)

	def main(self):
		self.topo()

a = Problem()
a.main()			