#https://www.acmicpc.net/problem/10986

import sys
input = sys.stdin.readline

n, div = map(int, input().split())

#arr for storing input
arr = list(map(int, input().split()))

# S[i] denote the number of sum sequnces arr[0] ~ arr[j] = sum[j] whose remainder is i when divided by div
# The reason why you have to make this.
# If you know the remainder of these, you can choose two with the same remainder among them.
# Let's say arr[0] ~ arr[j] and arr[0] ~ arr[k] (j < k) has the same remainder.
# Then (sum[k] - sum[j]) % div == 0, which means arr[j+1] ~ arr[k] is the sequence we are looking for.
# So, what you have to do is just make S[] arr and use combination.
# Let's say S[a] = b.
# Then we know there are b sequences with the same remainder. If you pick 2 from them, we can make a sequence that has no remainder when their sum is divided by div.
# Picking up two from b candidates can be computed as (b, 2) = b*(b-1)/2
# And finally, you have to add S[0] which is the number of sequences that already satisfies our condition.

S = [0] * div

total = 0
for i in range(n):
    total = (total + arr[i]) % div
    S[total] += 1

ans = 0
for i in range(div):
    ans += (S[i]*(S[i]-1))//2
ans += S[0]

print(ans)