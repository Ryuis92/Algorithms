# https://www.acmicpc.net/problem/1931
import sys
input = sys.stdin.readline

n = int(input())
time = []
no = [False for _ in range(n)]
for _ in range(n):
	time.append(list(map(int, input().split())))

#sort the time interval array in ascending order by finishing time, and starting time
time.sort(key = lambda x: (x[1], x[0]))	

count = 1
curr = time[0]
for i in range(1, n):
	# If two time interval is compatible, then the finishing time of current time interval is less than or equal to the starting time of another time interval.
	# This is ordered array, so finishing time of all intervals are greater than or equal to the current finishing time.
	if curr[1] <= time[i][0]:
		count +=1
		curr = time[i]
		
print(count)			