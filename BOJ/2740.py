# https://www.acmicpc.net/problem/2740

class problem:
	def __init__(self):
		self.a_size = list(map(int, input().split()))
		self.a = []
		for i in range(self.a_size[0]):
			self.a.append(list(map(int, input().split())))

		self.b_size = list(map(int, input().split()))
		self.b = []
		for i in range(self.b_size[0]):
			self.b.append(list(map(int, input().split())))

	def solve(self):
		a = self.a
		b = self.b

		for i in range(self.a_size[0]):
			for j in range(self.b_size[1]):
				res = 0
				for k in range(self.a_size[1]):
					res += a[i][k] * b[k][j]
				print(res, end= " ")
			print()	

a = problem()
a.solve()				