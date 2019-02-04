# https://www.acmicpc.net/problem/1021

size, out = map(int, input().split(" "))
arr = [i for i in range(1,size+1)]

count = 0
curr = 0	
out = list(map(int,input().split(" ")))
	
for o in out:
	pos_front = (arr.index(o) - curr) % len(arr)
	pos_back = len(arr)-pos_front
	
	#print("front: ", pos_front)
	#print("back: ", pos_back)

	if pos_front < pos_back:
		curr = (curr + pos_front) % len(arr)
		count += pos_front
	else:
		curr = (curr + pos_front) % len(arr)
		count += pos_back
	arr.pop(curr)
	#print("count: ", count)
	#print("curr: ", curr)
	#print(arr)
