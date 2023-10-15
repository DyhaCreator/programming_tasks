n = int(input())

a = [0] * (n + 1)
a[1] = 1

for i in range(2, n + 1):
    a[i] = float('inf')
    for j in range(1, int(i ** (1. / 3.)) + 1):
        if(a[i] > a[i - j ** 3] + 1):
            a[i] = a[i - j ** 3] + 1
print(a[n])