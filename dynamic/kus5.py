n, k = map(int, input().split())

frog = list(map(int, input().split()))

a = [0] * (n + 1)
a[0] = 1

for i in range(1, n + 1):
    ans = 0
    if(not(i in frog)):
        for j in range(max(0, i - k), i):
            ans += a[j]
            #print(a[j], end=' ')
    a[i] = ans
print(a[n])