# https://www.acmicpc.net/problem/11401
# ref: https://onsil-thegreenhouse.github.io/programming/problem/2018/04/02/problem_combination/

n, k = map(int, input().split())
DIV = 1000000007
fact = [1] * (n+1)
x = [1, 0]
y = [0, 1]
r = [DIV]

for i in range(1, n+1):
	fact[i] = (i * fact[i-1]) % DIV
 
down = (fact[k]*fact[n-k]) % DIV
r.append(down)


def euclid():
	"""
	solve Ax + By = gcd(A, B)

	down = (fact[k]*fact[n-k]) % DIV

	I want to solve DIV*x + down*y = gcd(DIV, down) = 1
	
	Using down* y = 1 (mod DIV),
	(fact[n]* (1/down)) % DIV = (fact[n]* (1/down) * 1) % DIV
							  = (fact[n]* (1/down) * down*y) % DIV	
							  = (fact[n]*y) % DIV
	"""
	re = r[0] % r[1]
	while re > 0:
		q = r[0] // r[1]

		r[0] = r[1]
		r[1] = re

		temp = x[0]
		x[0] = x[1]
		x[1] = temp - x[1]*q

		temp = y[0]
		y[0] = y[1]
		y[1] = temp - y[1]*q

		re = r[0] % r[1]

	return r[1]

######################################
# This is recursive version of it
# x = 0
# y = 0
# gcd = 0
# def euclid_recursive(a, b):
# 	c = a % b
# 	if c > 0:
# 		euclid_recursive(b, c)
# 		temp = y
# 		y = x - (a//b)* y
# 		x = temp
# 	else:
# 		x = 0
# 		y = 1
# 		gcd = b	
######################################

euclid()
result = (fact[n]* (y[1]) % DIV) % DIV
if result < 0:
	result += DIV

print(result)