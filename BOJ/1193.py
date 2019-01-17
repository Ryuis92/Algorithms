#https://www.acmicpc.net/problem/1193

ith = int(input())

def find_layer(num):
	if num == 1:
		return 1
	else:	
		n = 1
		while True:
			if n*(n-1)/2 + 1  <= num <= (n+1)*n/2:
				return n
			n += 1	

def find_sol(num):
	layer = find_layer(num)
	max = int(layer * (layer + 1) /2)
	min = int(layer * (layer - 1) /2 + 1)
	
	if layer % 2 == 0:
		dif = num -min
	else:
		dif = max - num	

	print(1+dif, layer-dif, sep="/")

find_sol(ith)