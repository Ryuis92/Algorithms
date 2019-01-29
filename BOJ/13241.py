# https://www.acmicpc.net/problem/13241

def GCD(a, b):
	while b:
		temp = a;
		a = b;
		b = temp % b;
	return a;	

a, b = map(int, input().split(" "))
gcd = GCD(max(a,b), min(a,b));
print(int(a*b/gcd))
