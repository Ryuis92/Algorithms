#https://www.acmicpc.net/problem/5622

arr = [3,3,3,4,4,4, 5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10]

dial = input()
total = 0
for letter in dial:
    if letter == '0':
        total += 11
    elif letter == '1':
        total += 2
    else:
        total += arr[ord(letter) - ord("A")]

print(total)