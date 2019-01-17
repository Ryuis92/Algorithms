#https://www.acmicpc.net/problem/2581

min_val = int(input())
max_val = int(input())
num = [i for i in range(0, max_val+1)]
num[1] = 0
total = 0

for i in range(2, max_val+1):
    if not num[i]:
        continue

    for j in range(2*i, max_val+1, i):
        num[j] = 0

for item in num[::-1]:
    if item >= min_val:
        total += item
        prime_min = item
if not total:
    print(-1)
else:
    print(total, prime_min, sep="\n")
