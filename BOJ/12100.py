# https://www.acmicpc.net/problem/12100
import sys
input = sys.stdin.readline

n = int(input())
board = []

for _ in range(n):
	board.append(list(map(int, input().split())))

def left():
	for i in range(n):
		temp = []

		for j in range(n):
			if board[i][j] != 0:
				temp.append(board[i][j])	

		board[i] = []
		temp_len = len(temp)
		
		j = 0
		while j < temp_len:
			if j+1 < temp_len:
				if temp[j] == temp[j+1]:
					board[i].append(temp[j]*2)
					j += 2
				else:
					board[i].append(temp[j])
					j += 1
			else:
				board[i].append(temp[j])
				j += 1

		for j in range(n - len(board[i])):
			board[i].append(0)

def right():
	for i in range(n):
		temp = []

		for j in range(n):
			if board[i][j] != 0:
				temp.append(board[i][j])	

		board[i] = []
		temp_len = len(temp)

		j = temp_len - 1
		while j >= 0:
			if j > 0:
				if temp[j] == temp[j-1]:
					board[i].append(temp[j]*2)
					j -= 2
				else:
					board[i].append(temp[j])
					j -= 1
			else:
				board[i].append(temp[j])
				j -= 1

		for j in range(n - len(board[i])):
			board[i].append(0)
		board[i] = board[i][::-1]

def up():
	for i in range(n):
		temp = []

		for j in range(n):
			if board[j][i] != 0:
				temp.append(board[j][i])	

		temp_len = len(temp)
		temp_col = []

		j = 0
		while j < temp_len:
			if j+1 < temp_len:
				if temp[j] == temp[j+1]:
					temp_col.append(temp[j]*2)
					j += 2
				else:
					temp_col.append(temp[j])
					j += 1
			else:
				temp_col.append(temp[j])
				j += 1

		for j in range(n - len(temp_col)):
			temp_col.append(0)

		for j in range(n):
			board[j][i] = temp_col[j]

def down():
	for i in range(n):
		temp = []

		for j in range(n):
			if board[j][i] != 0:
				temp.append(board[j][i])	

		temp_len = len(temp)
		temp_col = []

		j = temp_len - 1
		while j >= 0:
			if j > 0:
				if temp[j] == temp[j-1]:
					temp_col.append(temp[j]*2)
					j -= 2
				else:
					temp_col.append(temp[j])
					j -= 1
			else:
				temp_col.append(temp[j])
				j -= 1

		for j in range(n - len(temp_col)):
			temp_col.append(0)
		
		temp_col = temp_col[::-1]
		for j in range(n):
			board[j][i] = temp_col[j]

way = [left, right, up, down]
	
def getmax(count):
	if count == 5:
		ans = 0
		for i in range(n):
			for j in range(n):
				if ans < board[i][j]:
					ans = board[i][j]

		return ans

	temp_b = []
	for r in board:
		temp_b.append(r[:])


	ans = 0
	for i in range(4):
		move = way[i]
		move()
		ans = max(ans, getmax(count + 1))
		
		for i in range(n):
			board[i] = temp_b[i][:]

	return ans	

print(getmax(0))