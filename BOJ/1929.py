#https://www.acmicpc.net/problem/1929

m, n = map(int, input().split(" "))

prime = [i for i in range(0, n+1)]
prime[1] = 0

for i in range(2, n+1):
    if prime[i]:
        for j in range(i+i, n+1, i):
            prime[j] = 0

for p in prime:
    if p > n:
        break
    elif m <= p:
        print(p)