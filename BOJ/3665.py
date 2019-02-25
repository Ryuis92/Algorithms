# https://www.acmicpc.net/problem/3665
import sys
input = sys.stdin.readline

class Problem:
	def __init__(self):
		self.n = int(input())
		last = list(map(int, input().split()))
		self.m = int(input())
		self.adj = [[] for _ in range(self.n+1)]
		self.indegree = [0 for _ in range(self.n + 1)] 
		

		for i in range(len(last)):
			self.adj[last[i]] = last[i+1:]
			self.indegree[last[i]] += i

		for _ in range(self.m):
			first, second = map(int, input().split())
			if first in self.adj[second]:
				self.adj[second].remove(first)
				self.adj[first].append(second)
				self.indegree[first] -=1
				self.indegree[second] += 1
			else:
				self.adj[first].remove(second)
				self.adj[second].append(first)
				self.indegree[second] -= 1
				self.indegree[first] += 1

	def topo(self):
		q = []
		ans = []
		for i in range(1, self.n+1):
			if self.indegree[i] == 0:
				q.append(i)

		for _ in range(self.n):
			if len(q) > 1:
				print("?")
				return
			elif len(q) == 0:
				print("IMPOSSIBLE")
				return
				
			curr = q.pop()
			ans.append(curr)

			for after in self.adj[curr]:
				self.indegree[after] -= 1
				if self.indegree[after] == 0:
					q.append(after)		

		print(" ".join(map(str,ans)))			
	

	def main(self):
		self.topo()

case = int(input())
while case:
	case -=1
	a = Problem()
	a.main()