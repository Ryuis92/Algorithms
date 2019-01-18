#https://www.acmicpc.net/problem/1149
house_num = int(input())

total = 0
last = 0

pre_rgb = list(map(int,input().split(" ")))
nxt_rgb = [0] * 3
for i in range(0, house_num-1):
	r, g, b = map(int,input().split(" "))
	
	nxt_rgb[0] = r + min(pre_rgb[1], pre_rgb[2])
	nxt_rgb[1] = g + min(pre_rgb[0], pre_rgb[2])
	nxt_rgb[2] = b + min(pre_rgb[0], pre_rgb[1])

	pre_rgb = nxt_rgb[:]
	
print(min(nxt_rgb))	


"""
#Explanation

Let's say OPT(i,j) means that minimum total cost of painting i houses with the i-th house painted color j.
Here 1<= j <=3, 1 for red, 2 for green, 3 for blue. In this problem, i-th choice is affected, or coupled by the choice of (i-1)-th. 
So we need the information of which color is chosen in (i-1)-th selection. That's why OPT has two params i for the i-th house, and j for color
Now we can come up with recurrence relation about OPT. 

	OPT(i, j) = cost(i, j) + min(OPT(i-1, k)) (k is member of a set {1,2,3} - {j}) 

The code above is an implementation of this relation. Note, python list is like pointer. So this, pre_rgb = nxt_rgb, will not work as intended. 

"""