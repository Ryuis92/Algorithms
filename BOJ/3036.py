# https://www.acmicpc.net/problem/3036

def GCD(a, b):
	while b:
		c = a % b
		a = b
		b = c
	return a	

num = int(input())
rings = list(map(int, input().split()))
first = rings.pop(0)

for ring in rings:
	gcd = GCD(max(first, ring), min(first, ring))
	print("{}/{}".format(int(first/gcd), int(ring/gcd)))
