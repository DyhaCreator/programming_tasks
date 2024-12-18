n = int(input())
r = list('RGB')

n -= (n // 6) * 6

for i in range(n):
    if(i % 2 == 0):
        a = r[0]
        r[0] = r[1]
        r[1] = a
    else:
        a = r[1]
        r[1] = r[2]
        r[2] = a

print("".join(r))