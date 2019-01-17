#https://www.acmicpc.net/problem/2438
num = int(input())

for i in range(1, num+1):
    star = ""
    for j in range(0, i):
        star += "*"
    print(star)
