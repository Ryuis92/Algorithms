# https://www.acmicpc.net/problem/1325
import sys
input = sys.stdin.readline

class Problem:
	def __init__(self):
		self.n, self.m = map(int, input().split())
		self.tree = [[] for _ in range(self.n+1)]
		
		for _ in range(self.m):
			to, fr = map(int, input().split())
			self.tree[fr].append(to)
			
	def dfs(self, root):
		s = [root]
		count = 0
		bitmap = [False for _ in range(self.n+1)]
		bitmap[root] = True

		while len(s):
			p = s.pop()
			count += 1

			for child in self.tree[p]:
				if not bitmap[child]:
					s.append(child)
					bitmap[child] = True

		return count


	def main(self):
		ans = []
		for i in range(1, len(self.tree)):
			ans.append([self.dfs(i), i])

		ans.sort(key = lambda x: x[0], reverse = True)
		
		max_val = ans[0][0]
		for item in ans:
			if item[0] == max_val:
				print(item[1], end=" ")
			else:
				print()
				break	

a = Problem()
a.main()			