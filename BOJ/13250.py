#https://www.acmicpc.net/problem/13250
n = int(input())
memo = [-1 for _ in range(1000000+1)]

memo[0] = 0
memo[1] = 1
memo[2] = (memo[0] + memo[1])/ 6 + 1
memo[3] = (memo[0] + memo[1] + memo[2])/ 6 + 1
memo[4] = (memo[0] + memo[1] + memo[2] + memo[3])/ 6 + 1
memo[5] = (memo[0] + memo[1] + memo[2] + memo[3] + memo[4])/ 6 + 1

for i in range(6, n+1):
	# memo[i] denotes the expected number of rolling dice to get the total value of i.
	# A dice has six values: 1~ 6. So, memo[i] can be bulid from 6 previous memos.
	# Note this is expected value, which means average. 
	memo[i] = (memo[i-1] + memo[i-2] + memo[i-3] + memo[i-4]+memo[i-5] + memo[i-6] ) / 6 + 1

print(memo[n])	