# https://www.acmicpc.net/problem/4307
import sys
input = sys.stdin.readline

case = int(input())

while case:
	case -= 1

	length, ant = map(int, input().split())

	maxi = 0
	mini = 0
	for _ in range(ant):
		tmp = int(input())

		# biggest among the smaller part
		t_min = min(tmp, length - tmp)
		t_max = max(tmp, length - tmp)

		mini = max(t_min, mini)
		maxi = max(t_max, maxi)

	print(mini, maxi)