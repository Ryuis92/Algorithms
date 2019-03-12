# https://www.acmicpc.net/problem/2449
# With recursion
import sys
sys.setrecursionlimit(10**6)

bulb, color = map(int , input().split())
bulbs = list(map(int, input().split()))

memo = [[-1 for _ in range(200)] for _ in range(200)]

def coloring(s, e):
	"""
	returns total number of coloring when making s~e bulbs have same color
	"""
	if s == e:
		return 0;

	if memo[s][e] != -1:
		return memo[s][e]

	ans = 987654321
	# split s~e into two sub part
	# if two subpart have the same color (if bulbs[s] == bulbs[i+1]) then, no more coloring needed
	# else you have to color once more to make these 2 parts have the same color	
	for i in range(s, e):
		if bulbs[s] == bulbs[i+1]:
			plus = 0
		else:
			plus = 1
				
		ans = min(ans, coloring(s, i) + coloring(i+1, e) + plus)

	memo[s][e] = ans
	return ans


print(coloring(0, bulb-1))

##########################################################################################################################################
# Without recursion
##########################################################################################################################################

# The basic idea is the same, but in this implementation how to fill in the memo table is important
# This is initial table. We fill in the table in this way: You start from diagonal points and go up filling the table. 
# 0xxxx
# x0xxx
# xx0xx
# xxx0x
# xxxx0
#
# 0axxx
# x0xxx
# xx0xx
# xxx0x
# xxxx0
#
# 0abxx
# x0bxx
# xx0xx
# xxx0x
# xxxx0
#
# Like this
import sys

bulb, color = map(int , input().split())
bulbs = list(map(int, input().split()))

memo = [[0 for _ in range(bulb)] for _ in range(bulb)]

for i in range(bulb):
	for j in range(i, -1, -1):
		if i == j:
			continue
		memo[j][i] = 987654321	
			
		for k in range(j, i):
			if bulbs[j] == bulbs[k+1]:
				plus = 0
			else:
				plus = 1	
		
			memo[j][i] = min(memo[j][i], memo[j][k] + memo[k+1][i] + plus)

print(memo[0][bulb-1])