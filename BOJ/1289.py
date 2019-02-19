# https://www.acmicpc.net/problem/1289
import sys
input = sys.stdin.readline
MOD = 1000000007
NEXT = 0
WEIGHT = 1
sys.setrecursionlimit(10 ** 6)

class Problem:
	def __init__(self):
		self.line = int(input())
		self.graph = [ [] for i in range(self.line+1)]
		self.total = 0

		for i in range(self.line-1):
			fr, to , w = map(int, input().split())
			self.graph[fr].append([to, w])
			self.graph[to].append([fr, w])
		print(self.graph)	

	def dfs(self, root, parent):
		res = 0
		subtree = 0
		for node in self.graph[root]:
			if node[NEXT] == parent:
				continue
			sub = ((self.dfs(node[NEXT], root) + 1) * node[WEIGHT]) % MOD
			
			self.total = (self.total + sub) % MOD
			res =  (res + sub) % MOD	

			self.total = (self.total + sub*subtree) % MOD
			subtree = (subtree + sub) % MOD

		return res

	def main(self):
		self.dfs(1 , -1)
		print(self.total)

a = Problem()
a.main()