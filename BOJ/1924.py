#https://www.acmicpc.net/problem/1924

day = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
day_31 = [1, 3, 5, 7, 8, 10, 12]
day_30 = [4, 6, 9, 11]

mon_in, day_in = map(int, input().split(" "))
total = 0
for i in range(1,mon_in):
	if i == 2:
		total += 28
	elif i in day_30:
		total += 30
	else:
		total += 31
total += day_in
print(day[(total-1) % 7])
