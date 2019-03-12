import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def clearQuest(s, i):
	"""
	Return the maximum number of quests that can be cleared starting from 1,1
	"""
	if memo[s][i] != -1:
		return memo[s][i]
	
	stat = 0
	count = 0
	temp_clear = []

	for j in range(n) :
		#count quests that can be cleared
		#if it's first time, add stat
		if quest[j][0] <= s or quest[j][1] <= i:
			count +=1
			if not clear[j]:
				stat += quest[j][2]
				clear[j] = True
				temp_clear.append(j)

	if stat == 0:
		memo[s][i] = 0
		return 0			
				
	for j in range(stat+1):
		new_s = min(s + j, 1000)
		new_i = min(i + stat - j, 1000)
		count = max(count, clearQuest(new_s, new_i))
	
	# recover clear	
	for idx in temp_clear:
		clear[idx] = False	

	memo[s][i] = count
	
	return count


n = int(input())
quest = []
clear = [False for _ in range(n)]
#Size of memo don't need to be greater than 1000. 
memo = [[-1 for _ in range(1001)] for _ in range(1001)]

for i in range(n):
	quest.append(list(map(int, input().split())))

print(clearQuest(1,1))


