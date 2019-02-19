# https://www.acmicpc.net/problem/1167
from sys import stdin
input = stdin.readline
weight = 1
neighbor = 0

class Problem:
	def __init__(self):
		self.line = int(input())
		self.arr = [[] for i in range(self.line+1)]	
		self.initArr()	

	def initArr(self):
		for i in range(self.line):
			temp = list(map(int,input().split()))
			s = temp[0]
			for i in range(1,len(temp)-1, 2):
				self.arr[s].append([temp[i], temp[i+1]])

	def bfs(self, start):
		q = [start]
		res = [0 for i in range(self.line + 1)]
		bitmap = [False for i in range(self.line + 1)]
		ans = 0
		idx = start
		while len(q) != 0:
			p = q.pop(0)
			bitmap[p] = True

			for node in self.arr[p]:
				if not bitmap[node[neighbor]]:
					q.append(node[neighbor])
					res[node[neighbor]] = res[p] + node[weight]
					if ans < res[node[neighbor]]:
						ans = res[node[neighbor]]
						idx = node[neighbor]
		return (ans,idx)

	def main(self):
		ans, idx = self.bfs(1)
		ans, _ = self.bfs(idx)
		print(ans)		

a = Problem()
a.main()