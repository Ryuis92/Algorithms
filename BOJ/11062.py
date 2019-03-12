# https://www.acmicpc.net/problem/11062

import sys
input = sys.stdin.readline

def solve(left, right):
	if left > right:
		return 0

	if memo[left][right] != -1:
		return memo[left][right]

	# I want to minimize competitor's score, which means maximize my score
	ans_left = card[left] + min(solve(left+1, right - 1), solve(left+2, right))	
	ans_right = card[right] + min(solve(left + 1, right-1), solve(left, right-2))

	memo[left][right] = max(ans_left, ans_right)

	return memo[left][right]

case = int(input())

while case:
	case -= 1
	card_num = int(input())
	card = list(map(int, input().split()))

	memo = [[-1 for _ in range(card_num)] for _ in range(card_num)]

	print(solve(0, card_num-1))

############################################################################################################################

############################################################################################################################

import sys
input = sys.stdin.readline

def solve(left, right):
	#returns the maximum score you can get when given left and right position
	#escape condition
	if left > right:
		return 0
	#check memo
	if memo[left][right] != -1:
		return memo[left][right]

	# In my turn try to maximize my score, which means minimize competitor's score
	# if I choose card[left], then my score will be temp_sum - solve(left+1, right)
	# if I choose card[right], then my score will be temp_sum - solve(left, right-1)
	temp_sum = 0
	for i in range(left, right+1):
		temp_sum += card[i]

	ans_l = solve(left+1, right)
	ans_r = solve(left, right-1)

	#memorize
	memo[left][right] = temp_sum - min(ans_l, ans_r)

	return memo[left][right]

case = int(input())

while case:
	case -= 1
	card_num = int(input())
	card = list(map(int, input().split()))

	memo = [[-1 for _ in range(card_num)] for _ in range(card_num)]

	print(solve(0, card_num-1))

	