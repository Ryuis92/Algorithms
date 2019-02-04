# https://www.acmicpc.net/problem/1094

rod = [64]
X = int(input())
while sum(rod) != X:
	if sum(rod) > X:
		pop = rod.pop()
		if sum(rod) + int(pop/2) >= X:
			rod.append(int(pop/2))
		else:
			rod.append(int(pop/2))
			rod.append(int(pop/2))

print(len(rod))