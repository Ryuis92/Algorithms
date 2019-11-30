#https://www.acmicpc.net/problem/7579

n, m = map(int, input().split())
memory = list(map(int, input().split()))
cost = list(map(int, input().split()))

# memo[idx][totalCost]
# total available memory considering from idx-th app with the amount of cost as totalCost
memo = [[ -1 for _ in range(10000 + 1)] for _ in range(n)]

def findMem(idx, totalCost):
	# it basically finds max available memory with the constraint of totalCost
	if idx >= n:
		return 0

	if memo[idx][totalCost] != -1:
		return memo[idx][totalCost]

	# without idx-th app. don't kill it
	ans = findMem(idx + 1, totalCost)


	# if the cost of kill and re-mount idx-th app is within totalCost
	# then check which case gives more memory, one that kills idx-th app, the other not killing it
	if totalCost >= cost[idx]:
		ans = max(ans, memory[idx] + findMem(idx + 1, totalCost - cost[idx]))

	memo[idx][totalCost] = ans
	return ans

totalCost = 1
while True:
	if findMem(0, totalCost) >= m:
		print(totalCost)
		break
	totalCost += 1