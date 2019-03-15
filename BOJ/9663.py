# https://www.acmicpc.net/problem/9663

n = int(input())

def queen(row, visit):
	if row == n:
		return 1

	count = 0
	next_row = row + 1

	for i in range(1, n+1):
		flag = True
		for j in range(1, row+1):
			if visit[j] == i or abs(j - next_row) == abs(visit[j] - i):
				flag = False
				break

		if(flag):
			visit[next_row] = i
			count += queen(next_row, visit)

	visit[row] = 0		
			
	return count				

ans = 0

for i in range(1, n+1):
	visit = [0 for _ in range(n+1)]
	visit[1] = i
	ans += queen(1, visit)

print(ans)

###########################################################################################

n = int(input())

def queen(row, col, visit):
	visit.append([row, col])
	count = 0
	next_row = row + 1

	if next_row > n:
		visit.pop()
		return 1

	for i in range(1, n+1):
		flag = True
		for v in visit:
			if v[1] == i or abs((v[0] - next_row)/(v[1] - i)) == 1:
				flag = False
				break
		if(flag):
			count += queen(next_row, i, visit)
	
	visit.pop()

	return count	


ans = 0

for i in range(1, n+1):
	ans += queen(1, i, [])

print(ans)
