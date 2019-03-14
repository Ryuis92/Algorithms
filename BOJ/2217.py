# https://www.acmicpc.net/problem/2217

import sys
input = sys.stdin.readline

n = int(input())
rope = []

for _ in range(n):
	rope.append(int(input()))

rope.sort()

ans = 0

# you don't have to use all ropes.
# the maximum weight that can be tolerated when using n ropes it will be n * the minimum weight of n ropes that they can bear
for i in range(n):
	ans = max(ans, (n-i) * rope[i])

print(ans)

