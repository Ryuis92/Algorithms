# https://www.acmicpc.net/problem/1024
def getSumFromZeroTo(n):
	return int((n+1)*n/2)
def printArr(arr):
	for item in arr:
		print(item, end=" ")

N, L = map(int, input().split())

while True:
	total = getSumFromZeroTo(L-1)
	if total > N or L > 100:
		print(-1)
		break

	if (N - total) % L == 0:
		arr = [i + int((N - total)/L) for i in range(L)]
		printArr(arr)
		break
	else:
		L += 1		


'''
if the sum of L consecutive numbers is equal to N, then you can get to N starting from 0 + 1 + ... + L-1 (= getSumFromZeroTo(L-1))
You have it as a starting point. And move to right these numbers until the total of these numbers is equal to N.
This is actually adding 1 to all the numbers, which in total L. So, N - getSumFromZeroTo(L-1) must be divisible by L.
'''		