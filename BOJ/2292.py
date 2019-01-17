#https://www.acmicpc.net/problem/2292
def findLayer(num):
    i = 0;
    while True:
        if(formula(i) < num <= formula(i+1)):
            return i+1;
        i+=1

def formula(n):
    return 3*n*n + 3*n + 1


num = int(input())
if num == 1:
    print("1")
 
else:
    layer = findLayer(num)
    print(layer+1)