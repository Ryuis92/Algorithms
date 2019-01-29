# https://www.acmicpc.net/problem/1934

def GCD(a, b):
	while b:
		temp = a;
		a = b;
		b = temp % b;
	return a;	

line = int(input())		
while line:
	line -= 1
	a, b = map(int, input().split(" "))
	gcd = GCD(max(a,b), min(a,b));
	print(int(a*b/gcd))