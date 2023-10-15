n = int(input())
if(n == 0):
    exit(0)
a = [0] * (n + 1)
a[0] = 1
print(1)
for i in range(1, n):
    b = [0] * n
    for j in range(1, n):
        b[j] = a[j - 1]
    for j in range(len(b)):
        a[j] += b[j]
    for j in range(i + 1):
        print(a[j], end=' ')
    print()