# https://www.acmicpc.net/problem/2342
# Recursive implementation
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10** 6)

step_arr = list(map(int, input().split()))
step_arr.pop()
length = len(step_arr)
memo = [[[-1 for _ in range(5)] for _ in range(5)] for _ in range(length)]

def takeStep(left, right, step):
	if step >= length:
		return 0
	
	if memo[step][left][right] != -1:
		return memo[step][left][right]
	
	next_step = step_arr[step]	
	
	move_left = 0
	move_right = 0

	if left == 0:
		move_left = 2
	elif left - next_step == 0:
		move_left = 1
	elif abs(left - next_step) == 1 or abs(left - next_step) == 3:
		move_left = 3
	else:
		move_left = 4

	if right == 0:
		move_right = 2
	elif right - next_step == 0:
		move_right = 1
	elif abs(right - next_step) == 1 or abs(right - next_step) == 3:
		move_right = 3
	else:
		move_right = 4

	ans = min(takeStep(next_step, right, step + 1) + move_left, takeStep(left, next_step, step + 1) + move_right)
	memo[step][left][right] = ans

	return ans

print(takeStep(0,0,0))	

# Without recursion
import sys
input = sys.stdin.readline

step_arr = list(map(int, input().split()))
step_arr.pop()
length = len(step_arr)
memo = [[[987654321 for _ in range(5)] for _ in range(5)] for _ in range(length+1)]

memo[0][0][0] = 0

def calc(fr, to):
	if fr == 0:
		return 2
	elif fr == to:
		return 1
	elif abs(fr - to) == 1 or abs(fr - to) == 3:
		return 3
	else:
		return 4

# memo[i][l][r] means minimun moving energy needed to move i steps and After that, left foot is at l-th step and right foot is at r-th step.
# From memo[i], we can build memo[i+1].
# Let's say we have memo[i] and next step is next_step	
# If we move left foot memo[i+1][next_step][j] = memo[i][k][j] + calc(k, next_step) for all k. Our goal is to find the minimum. 
# so memo[i+1][next_step][j] = min(memo[i+1][next_step][j], memo[i][k][j] + dis)
for i in range(length):
	next_step = step_arr[i]

	for j in range(5):
		for k in range(5):
			dis = calc(k, next_step)
			#When left foot is at k-th step and moving to next_step
			memo[i+1][next_step][j] = min(memo[i+1][next_step][j], memo[i][k][j] + dis)
			#When right foot is at k-th step and moving to next_step
			memo[i+1][j][next_step] = min(memo[i+1][j][next_step], memo[i][j][k] + dis)	

ans = 987654321			

for i in range(5):
	for j in range(5):
		ans = min(ans, memo[length][i][j])

print(ans)		