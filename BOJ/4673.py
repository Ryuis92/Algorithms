#https://www.acmicpc.net/problem/4673

def snum(n):
	ans = n
	while n:
		ans += n % 10
		n = n // 10

	return ans

arr = []
n = 1

while n <= 10000:
	t = snum(n)
	n += 1

	if t > 10000:
		continue
	arr.append(t)

check = [False for _ in range(10001)]

for t in arr:
	check[t] = True

for i in range(1, 10001):
	if not check[i]:
		print(i)