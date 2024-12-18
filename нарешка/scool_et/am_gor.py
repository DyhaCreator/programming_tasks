n = int(input())

a = []
for i in range(n):
    a.append(int(input()))
ml = -1
mr = n + 2

for i in range(1, n - 1):
    l = i - 1
    r = i + 1
    if(a[l] < a[i] and a[r] < a[i]):
        print(l + 1)
        print(r + 1)
        exit(0)
    elif(a[l] < a[i] and a[r] == a[i]):
        while(r < n and a[r] == a[i]):
            r += 1
        if(a[r] < a[i] and r - l < mr - ml):
            ml = l
            mr = r
        i = r + 1
if(ml == -1 and mr == n + 2):
    print(0)
else:
    print(ml + 1)
    print(mr + 1)

'''

7
18
10
15
20
20
10
3

'''