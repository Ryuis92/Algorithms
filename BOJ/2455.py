# https://www.acmicpc.net/problem/2455

line = 4
total = 0
MAX = 0
while line:
	line -= 1
	getout, getin  = map(int, input().split(" "))
	total = total + getin - getout
	MAX = max(MAX, total)

print(MAX)	
