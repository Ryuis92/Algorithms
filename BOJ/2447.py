# https://www.acmicpc.net/problem/2447

class problem:
	def __init__(self):
		self.line = int(input())
		self.bitmap = [[1 for i in range(self.line)] for j in range(self.line)]
	
	def solve(self, start, end):
		length = int((end - start + 1)/3)
		if length == 0:
 			return

		for k in range(start + length, start + 2*length):
			i = length
			while i < self.line:
				self.bitmap[k][i:i+length] = [0 for j in range(length)]
				i += length * 3

		self.solve(start, start + length - 1)
		self.solve(start + length, start + 2 * length-1)				
		self.solve(start + 2 * length, end)			

	def printStar(self):
		bitmap = self.bitmap
		
		for i in range(len(bitmap)):
			for j in range(len(bitmap)):
				if bitmap[i][j] == 1:
					print("*", end="")
				else:
					print(" ", end="")
			print()		

	def main(self):
		self.solve(0, len(self.bitmap)-1)
		self.printStar()
		

a = problem()
a.main()

"""
In case when input is 27

***|***|***|***|***|***|***|***|***
* *|* *|* *|* *|* *|* *|* *|* *|* * 
***|***|***|***|***|***|***|***|***

***|   |***|***|   |***|***|   |*** 
* *|   |* *|* *|   |* *|* *|   |* * 
***|   |***|***|   |***|***|   |***

***|***|***|***|***|***|***|***|***
* *|* *|* *|* *|* *|* *|* *|* *|* *
***|***|***|***|***|***|***|***|***

*********|         |*********
* ** ** *|         |* ** ** *
*********|         |*********

***   ***|         |***   ***
* *   * *|         |* *   * *
***   ***|         |***   ***

*********|         |*********
* ** ** *|         |* ** ** *
*********|         |*********

***|***|***|***|***|***|***|***|***
* *|* *|* *|* *|* *|* *|* *|* *|* * 
***|***|***|***|***|***|***|***|***

***|   |***|***|   |***|***|   |*** 
* *|   |* *|* *|   |* *|* *|   |* * 
***|   |***|***|   |***|***|   |***

***|***|***|***|***|***|***|***|***
* *|* *|* *|* *|* *|* *|* *|* *|* *
***|***|***|***|***|***|***|***|***

Hint is that input is always the power of 3. So, split these example in terms of 3.
Then you can see the pattern. 




"""