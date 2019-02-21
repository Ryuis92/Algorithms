# https://www.acmicpc.net/problem/7569
import collections

class Problem:
	def __init__(self):
		self.col, self.row, self.floor = map(int, input().split())
		self.box = []

		for i in range(self.floor):
			temp_floor = []
			for j in range(self.row):
				temp_floor.append(list(map(int, input().split())))
			self.box.append(temp_floor)	

	def	bfs(self, arr):
		bitmap = [[[False for i in range(len(self.box[0][0]))] for j in range(len(self.box[0]))] for k in range(len(self.box))]
		six_way = [[1,0,0], [-1, 0,0], [0, 1,0], [0, -1,0],[0,0,1],[0,0,-1]]
		day = 0
		q = arr

		while len(q):
			# print(day)

			# for b in self.box:
			# 	print(b)

			push_size = len(q)
			while push_size:
				push_size -= 1	
				pfloor, prow, pcol = q.popleft()
				bitmap[pfloor][prow][pcol] = True

				for way in six_way:
					temp_row = prow + way[0]
					temp_col = pcol + way[1]
					temp_floor = pfloor + way[2]

					if 0<= temp_row < self.row and 0<= temp_col < self.col and 0 <= temp_floor < self.floor:
						if self.box[temp_floor][temp_row][temp_col] != -1 and not bitmap[temp_floor][temp_row][temp_col]:
							self.box[temp_floor][temp_row][temp_col] = 1
							q.append([temp_floor, temp_row, temp_col])
							bitmap[temp_floor][temp_row][temp_col] = True
		
			day +=1

		return day	
	
	def findRipe(self):
		arr = collections.deque([])

		for i in range(len(self.box)):
			for j in range(len(self.box[i])):
				for k in range(len(self.box[i][j])):
					if self.box[i][j][k] == 1:
						arr.append([i,j,k])
		return arr			

	def isRipe(self):
		flag = True
		for i in range(len(self.box)):
			for j in range(len(self.box[i])):
				for k in range(len(self.box[i][j])):
					if self.box[i][j][k] == 0:
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
