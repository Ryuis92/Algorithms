# https://www.acmicpc.net/problem/11399
# shortest job first
import sys
input = sys.stdin.readline

n = int(input())
time = list(map(int, input().split()))

time.sort()
ans = 0

total = sum(time)
minus = 0
for i in range(n-1,-1,-1):
	temp = total - minus
	minus += time[i]
	time[i] = temp

print(sum(time))