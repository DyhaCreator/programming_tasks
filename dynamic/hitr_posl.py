n = int(input())

a = [0] * (n + 1)
a[0] = 1
a[1] = 1

for i in range(2, n + 1):
    if(i % 2 == 0):
        if(i % 4 == 2):
            a[i] = a[i // 2] + 1
        else:
            a[i] = a[i - 1] - a[(i - 2) // 2]
print(a)