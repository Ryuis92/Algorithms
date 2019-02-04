# https://www.acmicpc.net/problem/1107

class problem:
	def __init__(self):
		self.target = input()
		self.num = int(input())
		self.start = 100
		if self.num:
			self.broken_key = list(map(int, input().split()))
		else:
			self.broken_key = []	
		self.key = [str(i) for i in range(10) if i not in self.broken_key]
		self.ans = abs(int(self.target) - self.start)

	def solve(self, sol):
		for k in self.key:
			temp_sol = sol + k
			self.ans = min(self.ans, len(temp_sol) + abs(int(temp_sol) - int(self.target)))
			
			if len(temp_sol) < 6:
				self.solve(temp_sol)
	
	def main(self):
		if self.num != 10:
			self.solve("")
		print(self.ans)		

a = problem()
a.main()	 	