# https://www.acmicpc.net/problem/10253
import math

case = int(input())

while case:
	case -= 1
	a, b = map(int, input().split())
	
	while a:
		p = math.ceil(b/a)
		a = a*p - b;
		b = b*p
		#print("p :{}, up: {} down: {}".format(p,a,b))

	print(p)

'''
How to find out the largest 1/x that are equal or less than a/b

1/x <= a/b
b <= ax
b/a <= x

so, b/a is the minimun x, which make 1/x the maximun. 
In case b is not divisible by a, you need get the ceiling of a/b.

'''	