#https://www.acmicpc.net/problem/1932

line = int(input())
prev_list = None
while line:
	line -= 1
	temp = list(map(int, input().split(" ")))
	
	next_list = []
	if not prev_list:
		prev_list = temp[:]
	else:
		#print(prev_list)

		for i in range(0, len(temp)):
			if 0 < i < len(temp) -1:
				val = temp[i] + max(prev_list[i-1], prev_list[i])
				next_list.append(val)
			elif 0 < i:	
				val = temp[i] + prev_list[i-1]
				next_list.append(val)
			else:
				val = temp[i] + prev_list[i]
				next_list.append(val)
		#print(next_list)
		prev_list = next_list[:]		

print(max(next_list))
