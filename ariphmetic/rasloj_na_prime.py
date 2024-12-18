a = int(input())

p = [2]
i = 3
while(i * i < a):
    b = True
    for j in range(len(p)):
        if(i % p[j] == 0):
            b = False
            break
    if(b):
        p.append(i)
    i+=1
while(a > 1):
    for i in range(len(p)):
        if(a % p[i] == 0):
            a = a // p[i]
            print(p[i])
            break