# https://www.acmicpc.net/problem/1562

length = int(input())
DIV = 1000000000
#memo[length][10][2**10]
#To check all numbers 0~9 are used, use bitmasking. Ten numbers need 10 bits, so 2 ** 10
#length denotes the length of a number. The second index means the number ends with the index number. 
memo = [[[0 for _ in range(2**10)] for _ in range(10)] for _ in range(length)]

#initial memo. Note tarting with 0 is not allowed.
for i in range(1,10):
	memo[0][i][1 << i] = 1

n = 1

#Total running time O(length * 10 * 2 **10)
while n < length:
	for j in range(2**10):
		#In case the number ends with 0
		memo[n][0][j | 1 << 0] = (memo[n][0][j | 1]+ memo[n-1][1][j]) % DIV

		#In case the number ends with 1~8
		for i in range(1,9):
			memo[n][i][j | 1 << i] = (memo[n][i][j | 1 << i]+ memo[n-1][i+1][j] + memo[n-1][i-1][j]) % DIV
		
		#In case the number ends with 9
		memo[n][9][j | 1 << 9] = (memo[n][9][j | 1 << 9] + memo[n-1][8][j]) % DIV

	n += 1

ans = 0
#add all memo[length-1][i][2**10-1]
for i in range(10):
	ans = (ans + memo[length-1][i][-1]) % DIV

print(ans)	