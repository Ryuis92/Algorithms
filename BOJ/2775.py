#https://www.acmicpc.net/problem/2775
line = int(input())

while line:
	line -= 1
	k = int(input())
	n = int(input())
	arr = [i for i in range(1, n+1)]
	
	for i in range(0, k):
		for j in range(1, n):
			arr[j] = arr[j] + arr[j -1]
	print(arr[n-1])