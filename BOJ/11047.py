# https://www.acmicpc.net/problem/11047
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coin = []

for _ in range(n):
	c = int(input())
	if c > k:
		continue
	coin.append(c)

count = 0

for i in range(len(coin)-1, -1, -1):
	count += k // coin[i]
	k = k % coin[i]

print(count)