n, q = map(int, input().split())

a = sorted(list(map(int, input().split())))
b = list(map(int, input().split()))

print(a)

for i in range(len(b)):
    l = 0
    r = len(a) - 1
    while(l < r):
        m = (l + r) // 2
        if(a[m] > b[i]):
            l = m
        else:
            r = m
    print(a[r])