# https://www.acmicpc.net/problem/1890
import sys
input = sys.stdin.readline

class Problem:
	def __init__(self):
		self.n = int(input())
		self.map = []
		self.memo =[[-1 for _ in range(self.n)] for _ in range(self.n)]
		self.two_way = [[0, 1], [1,0]]
		for _ in range(self.n):
			self.map.append(list(map(int, input().split())))
	
	def dfs(self, row, col):
		if self.memo[row][col] != -1:
			return self.memo[row][col]

		move = self.map[row][col]
		if move == 0:
			if (row, col) == (self.n - 1, self.n - 1):
				self.memo[row][col] = 1
				return 1
			else:
				return 0	

		res = 0
		for way in self.two_way:
			temp_row = row + move*way[0]
			temp_col = col + move*way[1]
			if 0 <= temp_row < self.n and 0 <= temp_col < self.n:
				res += self.dfs(temp_row, temp_col)

		self.memo[row][col] = res
		return res

	def main(self):
		print(self.dfs(0,0))	
	
a = Problem()
a.main()
