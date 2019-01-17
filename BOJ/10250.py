#https://www.acmicpc.net/problem/10250

line = int(input())
for i in range(0, line):
	h, w , num = map(int, input().split(" "))

	col = int(num / h)
	row = num % h

	if not row:
		row = h
		col -= 1

	if row < 10:
		print("{}{:02}".format(row, col+1))
	else:
		print("{:02}{:02}".format(row, col+1))
