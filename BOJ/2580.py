# https://www.acmicpc.net/problem/2580

board = []
blank = []

for _ in range(9):
	board.append(list(map(int, input().split())))


# find coords of blank spots
for i in range(9):
	for j in range(9):
		if board[i][j] == 0:
			blank.append([i, j])

def sudoku(idx,blank):
	"""
	fill in idx-th blank
	"""

	#filled all blanks
	if idx == len(blank):
		for i in range(9):
			for j in range(9):
				print(board[i][j], end=" ")
			print()
		exit(0)


	row, col = blank[idx]

	check = [False for _ in range(11)]

	#check row, col
	for i in range(9):
		check[board[row][i]] = True
		check[board[i][col]] = True

	#check small box of 3x3
	for i in range((row//3)*3, (row//3)*3 + 3):
		for j in range((col//3)*3, (col//3)*3 + 3):
			check[board[i][j]] = True

	for i in range(1, 10):
		if not check[i]:
			board[row][col] = i			
			sudoku(idx+1, blank)

	board[row][col] = 0	

sudoku(0, blank)	