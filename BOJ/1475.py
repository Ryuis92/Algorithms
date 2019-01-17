#https://www.acmicpc.net/problem/1475
import math

room_num = input()
arr = [0] * 9

for char in room_num:
	if char in ["9", "6"]:
		arr[6] += 0.5
	else:
		arr[int(char)] += 1
arr.sort()
print(math.ceil(arr[-1]))		