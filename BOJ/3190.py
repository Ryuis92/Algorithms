import collections

n = int(input())
k = int(input())

# store apple's position and state: visited or not
apple = [[False] * (n+1) for _ in range(n+1)]

# For move, you store the changes of direction. move is stored in ascending order so you have to popleft.
# For trace, you store the trace or current positions of all points the snake is consisted of.
# you have to delete the tail so popleft
move = collections.deque()
maps = [[False] * (n+1) for _ in range(n+1)]
trace = collections.deque()

for _ in range(k):
	y, x = map(int, input().split())
	apple[y][x] = True

l = int(input())
for _ in range(l):
	temp = input().split()
	temp[0] = int(temp[0])
	move.append(temp)

cur_x, cur_y = 1, 1
trace.append([1, 1])
maps[1][1] = True
time = 0
# 1 : right, 2: down, 3: left, 4: up
# you change direction 90 degree to the left or right, so assign the numbers to the directions accordingly.
d = 1

while True:
	#print("({},{})".format(cur_y, cur_x))
	time += 1

	#move head
	if d == 1:
		cur_x += 1
	elif d == 2:
		cur_y += 1
	elif d == 3:
		cur_x -= 1
	else:
		cur_y -= 1

	if not (1 <= cur_x <= n) or not (1 <= cur_y <= n):
		break

	#check if it hit itself
	if maps[cur_y][cur_x]:
		break
	
	maps[cur_y][cur_x] = True
	trace.append([cur_y, cur_x])

	#find apple	
	if apple[cur_y][cur_x]:
		apple[cur_y][cur_x] = False

	#If no apple, delete the tail
	else:
		p = trace.popleft()
		maps[p[0]][p[1]] = False

	#check if the snake have to change its direction.
	#you have to check only the first element of move arr.
	if move and move[0][0] == time:
		if move[0][1] == "L":
			d = (d - 1) % 4
			if d == 0:
				d = 4
		else:	
			d = (d + 1) % 4
			if d == 0:
				d = 4
		move.popleft()	

print(time)