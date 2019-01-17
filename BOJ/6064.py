#https://www.acmicpc.net/problem/6064
def gcd(a, b):
	while b:
		mod = a % b
		a = b
		b = mod
	return a	

def lcm(a, b):
	mod = gcd(a,b)
	return int(a*b/mod)

line = int(input())
while line:
	line -= 1
	m, n, x, y = map(int, input().split(" "))
	
	max = lcm(m,n)
	count = x
	xx = x
	yy = x % n
	if not yy:
		yy = n	

	while count <= max and not yy == y:
		if (yy + m) % n == 0:
			yy = n
		else:
			yy = (yy + m) % n
		count += m	

	if not yy == y:
		count = -1
	print(count)		

