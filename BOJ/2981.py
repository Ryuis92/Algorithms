# https://www.acmicpc.net/problem/2981
import math

line = int(input())
numbers = []
m = []
while line:
	line -= 1
	numbers.append(int(input()))

numbers.sort()
num = numbers[1] - numbers[0]

for i in range(2, int(math.sqrt(num)) + 1):
	if num % i == 0:
		if i == num/i:
			m.append(i)
		else:	
			m.append(i)
			m.append(int(num/i))
m.append(num)
m.sort()

for div in m:
	remain = numbers[0] % div
	flag = True
	for n in numbers:
		if n % div != remain:
			flag = False
			break
	if flag:
		print(div, end=" ")		

# Explanation
# A1 = A1/m*m + r
# A2 = A2/m*m + r
#	.....
# An = An/m*m + r
#
# Let's assume that m is the divider which make remainer of division as r for every A.
# So, what you have to do is find out the number m.
# 
# A2 - A1 = m*( ~ )
# A3 - A2 = m*( ~ )	
#	....
# An - An-1= m*( ~ )
#	
# As you can see m is a part of dividers of A2-A1, A3-A2, ... An - An-1
# To specify m, you have to find GCD of A2-A1, A3-A2, ... An - An-1 and all dividers of GCD can be m. 
# But, these will take long time. Instead of doing that, you just find out dividers of An - An-1. 
# And check if every number has same remainder when it is divided by the dividers you found. 
#		