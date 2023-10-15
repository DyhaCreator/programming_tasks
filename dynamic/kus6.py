n, k = map(int, input().split())

money = list(map(int, input().split()))

a = [0] * (n + 1)
a[0] = 0

for i in range(1, n + 1):
    ans = 0
    for j in range(max(0, i - k), i):
        ans = max(a[j], ans)
        #print(a[j], end=' ')
    a[i] = ans + money[i]
    #print(ans)
print(a[n])