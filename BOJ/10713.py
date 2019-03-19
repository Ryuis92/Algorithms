#https://www.acmicpc.net/problem/10713
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
city = list(map(int, input().split()))
count = [0] * n
a = []
b = []
c = []

for _ in range(n-1):
	t1, t2, t3 = map(int, input().split())
	a.append(t1)
	b.append(t2)
	c.append(t3)


for i in range(m-1):
	start = min(city[i], city[i+1])
	end = max(city[i], city[i+1])

	#count how many times each railroad used
	#Why this works
	#We initialized count with 0s.
	#These two lines tell you that you counted rairoads from start to end-1.
	#Let's say you travel to city 1 to 3.
	#Then count[0] = 1, count[1] = 0 count[2] = -1
	#by using accumulated sum of count, this works as 1 1 0.
	count[start-1] += 1
	count[end-1] -= 1
	
ans = 0
num = 0
for i in range(n-1):
	num += count[i]
	ans += min(num * a[i], num * b[i] + c[i]

print(ans)