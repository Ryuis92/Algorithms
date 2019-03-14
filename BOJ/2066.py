# https://www.acmicpc.net/problem/2066
import sys
sys.setrecursionlimit(10**6)
def solve(p1, p2, p3, p4, p5, p6, p7, p8, p9):
	"""
	When current position is given, returns the probility of completing the removal.
	"""

	#if all cards are removed, return 1
	if p1 <= 0 and p2 <= 0 and p3 <= 0 and p4 <= 0 and p5 <= 0 and p6 <= 0 and p7 <= 0 and p8 <= 0 and p9 <= 0:
		return 1

	if memo[p1][p2][p3][p4][p5][p6][p7][p8][p9] != -1:
		return memo[p1][p2][p3][p4][p5][p6][p7][p8][p9]	

	count = 0
	temp = [p1, p2, p3, p4, p5, p6, p7, p8, p9]
	pair = []
	
	#find pairs of numbers that have same number.
	for i in range(8):
		#When i-th don't have card left, pass
		if temp[i] <= 0:
			continue

		for j in range(i+1, 9):
			#When j-th don't have card left, pass	
			if temp[j] <= 0:
				continue

			if cards[i][temp[i]-1][0] == cards[j][temp[j]-1][0]:
				count += 1
				pair.append([i, j])

	ans = 0
	for _ in range(count):
		p = pair.pop()
		#remove cards
		temp[p[0]] -= 1
		temp[p[1]] -= 1
		
		ans = ans + solve(*temp) / count

		#recover cards
		temp[p[0]] += 1
		temp[p[1]] += 1

	memo[p1][p2][p3][p4][p5][p6][p7][p8][p9] = ans
	
	return ans	

cards = []
memo = [[[[[[[[[-1 for _ in range(5)] for _ in range(5)] for _ in range(5)] for _ in range(5)] for _ in range(5)] for _ in range(5)] for _ in range(5)] for _ in range(5)] for _ in range(5) ]
for _ in range(9):
	cards.append(list(input().split()))

print(solve(4,4,4,4,4,4,4,4,4))