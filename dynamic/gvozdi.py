n = int(input())

a = list(map(int, input().split()))

a.sort()

b = [0] * (n - 1)
b[0] = 1
b[n - 2] = 1

for i in range(2, n - 2):
    #print(a[i - 1], a[i], a[i + 1])
    if(a[i] - a[i - 1] < a[i + 1] - a[i]):
        b[i - 1] = 1
    else:
        b[i] = 1

#print(b)
ans = 0
for i in range(n - 1):
    if(b[i] == 1):
        ans += a[i + 1] - a[i]
print(ans)