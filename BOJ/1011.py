#https://www.acmicpc.net/problem/1011

'''
explanation

If you try some cases yourself and wirte down the answers you will get something like below:
1:	1		1

2:	11		1
------------
3:	111		2
4:	121

5:	1121	2	
6:	1221
------------
7:	12121	3
8:	12221
9:  12321

10:	122221 	3
11:	122321
12:	123321
------------
.
.
.

Now you can see the pattern. The code I put below is using this pattern.
The key point of the pattern is number of lines. When travel length is given(or start and end points),
you will be able to find in which group the lenth is lying. For example, if you are given 10, it is second half of 3rd.
With these in mind you can understand this code.

'''

def find_group(num):
	if num < 3:
 		return 0
	
	n = 1
	while True:
		if n*(n+1) < num <= (n+1)*(n+2):
			return n
		n += 1	

line = int(input())
while line: 
	line -= 1
	start, end = map(int, input().split(" "))
	group = find_group(end - start)

	if (group+1)*(group+2) - (end-start) < group+1:
		print(2*(group+1))
	else:
		print(2*group + 1)

####################################################
# if you want to see what and how steps are taken run the code below

# left = []
# right = []
# le = 0
# ri = 0
# mid = 1
# i = 0
# toLeft = True;
# while i<100:
# 	i += 1
# 	print(i, end = "  ")
# 	for item in left:
# 		print(item, end=" ")
# 	print("*",mid,"*", sep ="",end=" ")
# 	for item in right[::-1]:
# 		print(item, end=" ")
# 	print()		

# 	if mid + 1 - le > 1 or mid + 1 - ri > 1 :
# 		if len(left)> 1 and abs(le + 1 - mid) < 2 and abs(le + 1 -left[-2]) < 2:
# 			le +=1
# 			left[-1] = le
# 		elif len(right)>1 and abs(ri + 1 - mid) < 2 and abs(ri + 1 -right[-2]) < 2:
# 			ri +=1
# 			right[-1] = ri	
# 		else:
# 			if toLeft:
# 					left.append(mid)
# 					le = mid
# 					toLeft = False
# 			else:
# 					right.append(mid)
# 					ri = mid
# 					toLeft = True
# 			mid = 1
					
# 		while not( abs(mid - le) < 2 and abs(mid - ri) < 2)	:
# 			if le - mid > 1:
# 				le -= 1
# 				left[-1] = le
# 				mid +=1
# 			if ri - mid > 1:
# 				ri -=1
# 				right[-1] = ri
# 				mid +=1
# 	else:
# 		mid += 1

