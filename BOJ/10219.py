#https://www.acmicpc.net/problem/10219

# line = int(input())

# while line:
# 	line -= 1
# 	H, W = map(int, input().split())

# 	for i in range(0, H):
# 		grill = input()
# 		grill = grill[::-1]
# 		print(grill)

def symmetry(metrix):
	for i in range(0, len(metrix)):
		metrix[i] = metrix[i][::-1]

def showMap(a, b):
	for i in range(0, len(a)):
		for j in range(0, len(a[i])):
			if a[i][j] == 1:
				print("a", end="")
			elif b[i][j] == 1:
				print("b", end="")	
			else:	
				print(".", end="")
		print()			

line = int(input())

while line:
	line -= 1
	H, W = map(int, input().split())

	a = []
	b = []
	
	for i in range(0, H):
		temp = input()
		a_temp = []
		b_temp = []
		for j in range(0, W):
			if temp[j] == "a":
				a_temp.append(1)
				b_temp.append(0)
			elif temp[j] == "b":
				a_temp.append(0)
				b_temp.append(1)
			else:
				a_temp.append(0)
				b_temp.append(0)

		a.append(a_temp)
		b.append(b_temp)		
		
	symmetry(a)
	symmetry(b)
	showMap(a,b)	
