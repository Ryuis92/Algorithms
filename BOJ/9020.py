#https://www.acmicpc.net/problem/9020
import sys

line = int(input())
num = [i for i in range(0, 10000)]
num[1] = 0
total = 0

for i in range(2, 10000):
    if not num[i]:
        continue
    for j in range(2*i, 10000, i):
        num[j] = 0
                
while line:
    line -= 1
    even = int(input())  
    mid = int(even/2) 
    for i in range(0, mid-1):
        if num[mid+i] and num[mid-i]:
            print(mid-i ,mid + i)
            break