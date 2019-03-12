#https://www.acmicpc.net/problem/1958

#recursion
import sys
sys.setrecursionlimit(10**6)

str1 = input()
str2 = input()
str3 = input()

length1 = len(str1)
length2 = len(str2)
length3 = len(str3)

memo = [[[-1 for _ in range(length3)] for _ in range(length2)] for _ in range(length1)]

def lcs(i, j, k):
	if i< 0 or j < 0 or k < 0:
		return 0

	if memo[i][j][k] != -1:
		return memo[i][j][k]	
		
	ans = 0	
	if str1[i] == str2[j] and str2[j] == str3[k]:
		ans = 1 + lcs(i-1, j-1, k-1)
	elif str1[i] == str2[j]:
		ans = max(lcs(i,j,k-1), lcs(i-1, j-1, k))
	elif str2[j] == str3[k]:
		ans = max(lcs(i-1, j, k), lcs(i, j-1, k-1))
	elif str1[i] == str3[k]:
		ans = max(lcs(i, j-1, k), lcs(i-1, j, k-1))
	else:
		ans = max(lcs(i, j-1, k-1), lcs(i-1, j, k-1), lcs(i-1,j-1, k))

	memo[i][j][k] = ans

	return ans
		
print(lcs(length1-1,length2-1,length3-1))			

############################################################################################################
#without recursion
import sys
sys.setrecursionlimit(10**6)

str1 = input()
str2 = input()
str3 = input()

length1 = len(str1)
length2 = len(str2)
length3 = len(str3)

memo = [[[0 for _ in range(length3+1)] for _ in range(length2+1)] for _ in range(length1+1)]

for i in range(1,length1+1):
	for j in range(1,length2+1):
		for k in range(1,length3+1):
			if str1[i-1] == str2[j-1] and str2[j-1] == str3[k-1]:
				memo[i][j][k] = 1 + memo[i-1][j-1][k-1]
			elif str1[i-1] == str2[j-1]:
				memo[i][j][k] = max(memo[i][j][k-1], memo[i-1][j-1][k])
			elif str2[j-1] == str3[k-1]:
				memo[i][j][k] = max(memo[i-1][j][k], memo[i][j-1][k-1])
			elif str1[i-1] == str3[k-1]:
				memo[i][j][k] = max(memo[i][j-1][k], memo[i-1][j][k-1])
			else:
				memo[i][j][k] = max(memo[i][j-1][k-1], memo[i-1][j][k-1], memo[i-1][j-1][k])

				
print(memo[length1][length2][length3])			
