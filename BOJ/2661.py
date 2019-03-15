# https://www.acmicpc.net/problem/2661

n = int(input())

def sequence(num, l):
	if l == n:
		print(num)
		exit(0)

	for i in range(1,4):
		temp = 10 * num + i
		flag = True

		for j in range(1, (l+1)//2+1):
			d = (10 ** j)
			if temp % d == (temp // d) % d:
				flag = False
				break
		
		if(flag):
			sequence(temp, l+1)


sequence(0, 0)