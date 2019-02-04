# https://www.acmicpc.net/problem/1547

line = int(input())
ball = 1

while line:
	line -= 1

	a, b = map(int, input().split(" "))
	if a == ball:
		ball = b
	elif b == ball:
		ball = a
		
print(ball)			