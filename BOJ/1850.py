# https://www.acmicpc.net/problem/1850
class Problem:
	def GCD(self, a, b):
		while b:
			c = a % b
			a = b
			b = c
		return a

	def solve(self):
		a, b = map(int, input().split(" "))
		gcd = self.GCD(max(a,b), min(a,b))

		for i in range(0, gcd):
			print(1 , end="")

a = Problem()
a.solve()