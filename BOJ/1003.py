#https://www.acmicpc.net/problem/1003

line = int(input())
ones = [0] * 41
ones[1] = 1
zeros = [0] * 41
zeros[0] = 1

for i in range(2,41):
	zeros[i] = zeros[i-1] + zeros[i-2]
	ones[i] = ones[i-1] + ones[i-2]

while line:
	line -= 1
	num = int(input())
	print(zeros[num], ones[num])
	
	