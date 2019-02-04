# https://www.acmicpc.net/problem/3163
import collections
import sys

case = int(input())
input = sys.stdin.readline
while case:
	case -= 1

	ant_num, rod_len, k = map(int, input().split())

	arr = [[0,0] for i in range(ant_num)]
	arr_id = collections.deque(range(ant_num))
	drop = [[0,0] for i in range(ant_num)]
	
	
	for i in range(0, ant_num):
		curr, ant_id = map(int, input().split())
		if ant_id > 0:
			curr = rod_len - curr
		arr[i] = curr, ant_id
		arr_id[i] = ant_id
	
	arr.sort()

	for i in range(0, ant_num):
		if arr[i][1] > 0:
			drop[i] = arr[i][0], arr_id.pop()
		else:	
			drop[i] = arr[i][0], arr_id.popleft()

	drop.sort()
	print(drop[k-1][1])		