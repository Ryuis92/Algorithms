# https://www.acmicpc.net/problem/2178
import collections
class Problem:
	def __init__(self):
		self.n, self.m  = map(int, input().split())
		self.bitmap = [[False for _ in range(self.m)] for _ in range(self.n)]
		self.map = []

		for _ in range(self.n):
			self.map.append(input())

		for i in range(self.n):
			for j in range(self.m):
				if self.map[i][j] == '0':
					self.bitmap[i][j] = True

	def bfs(self, row, col):
		q = collections.deque([[row, col]])
		count = 1
		
		self.bitmap[row][col] = True
		four_way = [[0,1], [0,-1], [1,0],[-1,0]]

		while len(q):
			pop_num = len(q)

			while pop_num:
				pop_num -= 1

				prow, pcol = q.popleft()
				#print(prow, pcol, count)
				if (prow, pcol) == (self.n -1, self.m -1):
					return count

				

				for way in four_way:
					temp_row = prow + way[0]
					temp_col = pcol + way[1]
					if 0<= temp_row < self.n and 0<= temp_col < self.m:
						if not self.bitmap[temp_row][temp_col]:
							q.append([temp_row, temp_col])
							self.bitmap[temp_row][temp_col] = True
			count += 1	
				
						
	def main(self):
		print(self.bfs(0,0))	

a = Problem()
a.main()