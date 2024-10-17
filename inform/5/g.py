n = int(input())

a = [1, 2, 3]
for i in range(3, n):
    a.append(a[i - 1] + a[i - 2] - 2 * a[i - 3])
for i in a:
    print(i, end=' ')
print()