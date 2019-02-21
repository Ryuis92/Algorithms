# https://www.acmicpc.net/problem/2667

n = int(input())
arr = []

for i in range(n):
	arr.append(input())

bitmap = [[False for _ in range(n)] for _ in range(n)]

def dfs(row, col,bitmap, arr):
	s = [[row, col]]
	bitmap[row][col] = True
	four_way = [[0,1], [0,-1], [1,0], [-1, 0]]
	count = 0
	while len(s):
		prow, pcol = s.pop()
		count += 1
		for way in four_way:
			temp_row = prow + way[0]
			temp_col = pcol + way[1]
			if 0<= temp_row < len(arr) and 0<= temp_col < len(arr):
				if not bitmap[temp_row][temp_col] and arr[temp_row][temp_col] == '1':
					s.append([temp_row, temp_col])
					bitmap[temp_row][temp_col] = True

	return count				

ans = []			
for i in range(n):
	for j in range(n):
		if arr[i][j] == '0':
			bitmap[i][j] = True
		elif not bitmap[i][j]:
			ans.append(dfs(i, j, bitmap, arr))
ans.sort()

print(len(ans))

for a in ans:
	print(a)			