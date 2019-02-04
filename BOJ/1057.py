# https://www.acmicpc.net/problem/1057

import math
total, a, b = map(int, input().split(" "))
count = 1
a, b = min(a,b), max(a,b)

while int(math.log(total, 2)) + 1 >= count:
	if b % 2 == 0 and b == a + 1:
		print(count)
		break
	else:
		count += 1
		a = math.ceil(a/2) 
		b = math.ceil(b/2)

if int(math.log(total, 2)) + 1 < count:
	print(-1)		