# https://www.acmicpc.net/problem/10272
# ref : https://www.acmicpc.net/problem/2618
# police car problem is the same as this problem
"""
In this problem, you have to handle two travels. One is a forward travel from planet 1 to N. The other is a backward travel from planet N to 1.
Except planet 1 and N, these two travel must not have common visited planets. If they have, then it will obviously not be the shortest path.

Note for the backward travel, we can assume it as another forward travel. Just reverse the order of backward travel. 
So, now it become the same problem as the police car problem. For each planet you have to decide which travel ship, forward or backward, will visit it.

memo[l][r] denotes the minimun distance to go when foward travel ship is at l-th planet and backward travel ship is at r-th planet 
"""
import sys
import math
input = sys.stdin.readline

def dist(x1, y1, x2, y2):
	return math.sqrt((x1 - x2) **2 + (y1 - y2)**2)

def travel(ship1, ship2):
	#if one of the two ship has arrived at the end point, that means every planet has been visited.
	#So you don't have to travel more. send the other ship straight to the final destination
	if ship1 == n-1:
		return dist(x[ship2], y[ship2], x[n-1], y[n-1])
	if ship2 == n-1:
		return dist(x[ship1], y[ship1], x[n-1], y[n-1])	


	if memo[ship1][ship2] != -1:
		return memo[ship1][ship2]

	next_planet = max(ship1, ship2) + 1

	ship1_move = travel(ship1, next_planet) + dist(x[ship2], y[ship2], x[next_planet], y[next_planet])
	ship2_move = travel(next_planet, ship2) + dist(x[ship1], y[ship1], x[next_planet], y[next_planet])

	ans = min(ship1_move, ship2_move)

	memo[ship1][ship2] = ans

	return ans	


case = int(input())
while case:
	case -= 1
	n = int(input())
	x = []
	y = []	
	memo = [[-1 for _ in range(n)] for _ in range(n)]
	for _ in range(n):
		tx, ty = map(int, input().split())
		x.append(tx)
		y.append(ty)

	print(travel(0,0))	