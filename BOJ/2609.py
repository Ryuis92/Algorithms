# https://www.acmicpc.net/problem/2609

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
		print("{}\n{}".format(gcd, int(a*b/gcd)))

a = Problem()
a.solve()