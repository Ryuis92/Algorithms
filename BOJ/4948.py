#https://www.acmicpc.net/problem/4948
end = 123456*2+1
num = [i for i in range(0, end)]
num[1] = 0

for i in range(2, end):
    if not num[i]:
        continue

    for j in range(2*i, end, i):
        num[j] = 0

n = int(input())
        
while n:
    count = 0
    
    for i in range(n+1, 2*n + 1):
        if num[i] :
            count += 1
    print(count)
    n = int(input())
    