# https://www.acmicpc.net/problem/1780

class problem:
	def __init__(self):
		self.paper = []
		self.by = int(input())

		for i in range(self.by):
			self.paper.append(list(map(int,input().split())))
			
	def isSame(self, x1, y1, x2, y2):
		first = self.paper[y1][x1]
		for i in range(y1, y2 + 1):
			for j in range(x1, x2 + 1):
				if first != self.paper[i][j]:
					return False
		return True			

	def solve(self, x1, y1, x2, y2):
		count = [0,0,0]
		if (x1 == x2 and y1 == y2) or self.isSame(x1, y1, x2, y2):
			count[self.paper[y1][x1] + 1] += 1
			return count		
		else:
			width = int((x2 - x1 + 1)/3)
			height = int((y2- y1 + 1)/3)

			for i in range(3):
				for j in range(3):
					res = self.solve(x1 + width*j, y1 + height * i, x1 + width*(j+1)-1, y1 + height * (i+1)-1)
					count[0] += res[0]
					count[1] += res[1]
					count[2] += res[2]
			return count		

	def main(self):
		count = self.solve(0, 0, self.by-1, self.by-1)
		print(count[0], count[1], count[2], sep = "\n")		

a = problem()
a.main()