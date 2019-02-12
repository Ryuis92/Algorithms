# https://www.acmicpc.net/problem/1992

class problem:
	def __init__(self):
		self.length = int(input())
		self.bitmap = []

		for i in range(self.length):
			tmp = list(list(input()))
			self.bitmap.append(tmp)

	def isSame(self, x1, y1, x2, y2):
		first = self.bitmap[y1][x1]
		for i in range(x1, x2 + 1):
			for j in range(y1, y2 + 1):
				if first != self.bitmap[j][i]:
					return False
		return True	

	def solve(self, x1, y1, x2, y2):
		if self.isSame(x1, y1, x2, y2):
			return self.bitmap[y1][x1]
		else:
			width = int((x2 - x1 + 1)/2)
			height = int((y2 - y1 + 1)/2)
			res = "("
			for i in range(2):
				for j in range(2):
					res += self.solve(x1 + width*j, y1 + height * i, x1 + width*(j+1) - 1, y1 + height * (i+1) - 1)			
			res += ")"
			return res

	def main(self):
		res = self.solve(0, 0, self.length-1, self.length-1)
		print(res)

a = problem()
a.main() 		