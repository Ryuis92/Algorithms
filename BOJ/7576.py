# https://www.acmicpc.net/problem/7576
import collections

class Problem:
	def __init__(self):
		self.col, self. row = map(int, input().split())
		self.box = []

		for i in range(self.row):
			self.box.append(list(map(int, input().split())))

	def	bfs(self, arr):
		bitmap = [[False for i in range(len(self.box[0]))] for j in range(len(self.box))]
		four_way = [[1,0], [-1, 0], [0, 1], [0, -1]]
		day = 0
		q = arr

		while len(q):
			# print(day)

			# for b in self.box:
			# 	print(b)

			push_size = len(q)
			while push_size:
				push_size -= 1	
				prow, pcol = q.popleft()
				bitmap[prow][pcol] = True

				for way in four_way:
					temp_row = prow + way[0]
					temp_col = pcol + way[1]
					if 0<= temp_row < self.row and 0<= temp_col < self.col:
						if self.box[temp_row][temp_col] != -1 and not bitmap[temp_row][temp_col]:
							self.box[temp_row][temp_col] = 1
							q.append([temp_row, temp_col])
							bitmap[temp_row][temp_col] = True
		
			day +=1

		return day	
	
	def findRipe(self):
		arr = collections.deque([])

		for i in range(len(self.box)):
			for j in range(len(self.box[i])):
				if self.box[i][j] == 1:
					arr.append([i,j])
		return arr			

	def isRipe(self):
		flag = True
		for i in range(len(self.box)):
			for j in range(len(self.box[i])):
				if self.box[i][j] == 0:
					flag = False
					break
		return flag			
	
	def main(self):
		if self.isRipe():
			print(0)
		else:
			arr = self.findRipe()
			day = self.bfs(arr) - 1
			if self.isRipe():
				print(day)
			else:
				print(-1)	

a = Problem()
a.main()

"""
Use deque and popleft() instead of list and pop(0) if there's many pop(0)s. pop(0) is much slower

"""
