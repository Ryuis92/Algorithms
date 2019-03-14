# https://www.acmicpc.net/problem/3946
# ref : https://www.reddit.com/r/dailyprogrammer/comments/16dbyh/011113_challenge_116_hard_maximum_random_walk/
import sys
sys.setrecursionlimit(10**6)

def walk(n, f):
	"""
	returns the expected right most position visited after n movements starting from 0 when current right most position is at f.
	So from this definition, if current right most position is f and if you start k instead of 0, the expexted position will be walk(n, f-k) + k

	0--------------k-----f

	Let's put it on a 1D line. if you start at k, then the distance btw k and f is f-k. Now attract it to the origin

	k-----f

	Replace k to 0

	0-----(f-k)

	Now you can use walk(n, f-k) to find the right most position when you start from 0 and when the current flag is at f-k.
	After you call walk(n, f-k), you have to +k because you pulled k to 0.	
	
	"""
	if n == 0: 
		return f

	key = n, f
	if key not in cache:
		EL = walk(n-1,f+1) - 1
		E0 = walk(n-1,f)
		ER = walk(n-1, max(f-1, 0)) + 1

		cache[key] = L * EL + R * ER + (1-L-R) * E0
		
	return cache[key]

case = int(input())
while case:
	case -= 1
	n, L, R = input().split()
	n = int(n)
	L = float(L)
	R = float(R)
	
	cache = {}

	print("{0:.4f}".format(walk(n, 0)))
