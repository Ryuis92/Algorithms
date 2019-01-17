#https://www.acmicpc.net/problem/2941

inputs = input()
total = 0
for i in range(0, len(inputs)):
    if inputs[i] == "-":
        continue
    elif inputs[i] == "=":
        if inputs[i-2:i+1] == "dz=":
            total -= 1
        else:
            continue
    elif inputs[i] == "j" and (i> 0 and (inputs[i-1] == "n" or inputs[i-1] == "l")):
        continue
    else:
        total += 1
        
print(total)