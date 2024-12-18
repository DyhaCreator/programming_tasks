from copy import deepcopy

n = int(input())

def s(a):
    sf = 0
    ss = 0
    for i in range(len(a)):
        if(a[i][1] == 1):
            sf += a[i][0]
        else:
            ss += a[i][0]
    return abs(sf - ss)

a = []
for i in range(n):
    a.append(list(map(int, input().split())))
a.append([0, 1])
#print(a)
#print(s(a))

m = s(a)

for i in range(0, len(a)):
    for j in range(i + 1, len(a)):
        b = deepcopy(a)
        if(b[i][1] == 1):
            b[i][1] = 2
        else:
            b[i][1] = 1
        if(b[j][1] == 1):
            b[j][1] = 2
        else:
            b[j][1] = 1
        m = min(s(b), m)
        #print(s(b))
        #print(b)

print(m)