#https://www.acmicpc.net/problem/1344
# Dynamic programming version
a = int(input())/100
b = int(input())/100

prime = [2,3,5,7,11,13,17]
memo = [[[0 for _ in range(19)] for _ in range(19)] for _ in range(19)]

#base case
memo[1][0][0] = (1-a) * (1-b)
memo[1][0][1] = (1-a) * b
memo[1][1][0] = a * (1-b)
memo[1][1][1] = a * b

for k in range(2,19):
	for i in range(0, k+1):
		for j in range(0,k+1):
			#Both A and B don't score
			memo[k][i][j] += memo[k-1][i][j] * (1 - a) * (1 - b)
			if i >0:
				#Only A scores
				memo[k][i][j] += memo[k-1][i-1][j] * a * (1 - b)
			if j > 0:
				#Only B scores
				memo[k][i][j] += memo[k-1][i][j-1] * (1 - a)* b
			if i > 0 and j > 0:
				#Both A and B score	
				memo[k][i][j] += memo[k-1][i-1][j-1] * a * b

ans = 0
# After 18 sessions, check total score of A and B if at least one of them is a prime number.
for i in range(0, 19):
	for j in range(0,19):
		if i in prime or j in prime:
			ans += memo[18][i][j]

print(ans)

####################################################################

a = int(input())/100
b = int(input())/100

def probability(n, p):
	"""
	return the combination value given the posivie count n and probabilty p
	"""
	return factorial[18]/(factorial[n] * factorial[18-n]) * (p**n) * ((1-p)**(18-n))

prime = [2,3,5,7,11,13,17]
factorial = [1 for _ in range(19)]


for i in range(1,19):
	factorial[i] = factorial[i-1]*i

res_a = 0
res_b = 0

for p in prime:
	res_a += probability(p, a)
	res_b += probability(p, b)

print(1- (1 - res_a) * (1 - res_b))	
