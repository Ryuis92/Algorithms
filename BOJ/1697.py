# https://www.acmicpc.net/problem/1697

import collections
a, b = map(int, input().split())
limit = 100000

q = collections.deque()
q.append([a, 0])
visit = [False for _ in range(limit+1)]
visit[a] = True

while q:
    p = q.popleft()

    if p[0] == b:
        print(p[1])
        exit(0)

    nxt = p[1] + 1

    if 0 <= p[0] - 1 and not visit[p[0]-1]:
        q.append([p[0]-1, nxt])
        visit[p[0]-1] = True
    if p[0] + 1 <= limit and not visit[p[0]+1]:
        q.append([p[0]+1, nxt])
        visit[p[0]+1] = True
    if p[0]*2 <= limit and not visit[p[0]*2]:
        q.append([p[0]*2, nxt])
        visit[p[0]*2] = True    


###########################################################################
# more difficult version
# Initial positions of a, b are given as input
# A moves +1, +2, +3, +4, ... for each second
# B can move from b to b-1, b+1, or 2*b
#  
# What is the minimum time B can catch or meet A.
# If not possible print -1

import collections
import sys
sys.setrecursionlimit(10**6)
a, b = map(int, input().split())
limit = 200000

q = collections.deque()

visit = [-1 for _ in range(limit+1)]
visit[b] = 0
q.append([b, 0])

# find shortest movement count from b to i
while q:
    p = q.popleft()
    nxt = p[1] + 1
    if p[0] + 1 <= limit and visit[p[0] + 1] == -1:
        visit[p[0] + 1] = nxt
        q.append([p[0]+1, nxt])

    if 0<= p[0] - 1 and visit[p[0] - 1] == -1:
        visit[p[0] -1] = nxt
        q.append([p[0] - 1, nxt])        

    if p[0] * 2 <= limit and visit[p[0]*2] == -1 : 
        visit[p[0]*2] = nxt
        q.append([p[0]*2, nxt])

i = 0
while True:       
    #current position of a
    pos = a + (i * (i + 1))//2
    if pos > limit:
        break

    # If the minimum number of movements from b to pos is less than or equal to the number of movements of a
    # If they are equal, then fine.
    # If i is greater, then their difference must be even number.
    # The thing that i is greater than visit[pos] means that b arrived at pos earlier than a.
    # So, b have to use his free time by moving back and forth (-1, +1)

    if i >= visit[pos] and (visit[pos] - i) % 2 == 0:
        print(i)
        exit(0)
    i += 1    
print(-1)                