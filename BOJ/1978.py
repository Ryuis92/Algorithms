#ttps://www.acmicpc.net/problem/1978
num = int(input())
input_list = list(map(int,input().split()))
count = 0
for prime in input_list:
    if prime == 1:
        continue

    is_prime = True
    for i in range(2, int(prime/2) + 1):
        if prime % i == 0:
            is_prime = False
            break;
    if is_prime:
        count += 1
print(count)
