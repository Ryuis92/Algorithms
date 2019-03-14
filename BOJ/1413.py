# https://www.acmicpc.net/problem/1413
# ref : http://wookje.dance/2017/04/14/boj-1413-%EB%B0%95%EC%8A%A4-%EC%95%88%EC%9D%98-%EC%97%B4%EC%87%A0/
# Stirling numbers of the first kind
def gcd(a, b):
	while b:
		c = a % b
		a = b
		b = c
	return a	

n, m = map(int, input().split())
memo = [[0 for _ in range(21)] for _ in range(21)]

# To get all keys, the boxes must form cycle.
# So if all boxes are in a cycle, then no matter what box you choose to break, you will get all key eventually
# If there are cycles less than or equal to the number of bombs, you can get all keys.
# memo[i][j] denotes the Stirling number of making j cycles from i
# memo[i][j] = memo[i-1][j-1] + (i-1)*memo[i-1][j], this formula can be interpreted as sitting i people in j round tables
# if i-1 people already have sat in j-1 tables, and last one decided to sit alone, this will be memo[i-1][j-1]
# if i-1 people already have sat in j tables, the last one have to decide next to which person to sit. So, (i-1)*memo[i-1][j]
# For example there are 1 table and 3 people are there already. Then there are 3 possible position to sit.
for i in range(1, n+1):
	for j in range(1, i+1):
		if i == j:
			memo[i][j] = 1
		else:	
			memo[i][j] = memo[i-1][j-1] + (i-1)*memo[i-1][j]

# if you add up all meme[n] then it is the same as n!
for i in range(1, n+1):
	memo[n][i] += memo[n][i-1]

div = gcd(memo[n][n], memo[n][m])

print("{}/{}".format(memo[n][m]//div, memo[n][n]//div))