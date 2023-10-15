import sys

n = int(input())
sys.set_int_max_str_digits(1000000000)

a = [0] * (n + 1)
for i in range(n + 1):
    a[i] = [0, 0, 0]
a[1][0] = 1
a[1][1] = 1
a[1][2] = 1
for i in range(2, n + 1):
    a[i][0] = a[i - 1][1] + a[i - 1][2]
    a[i][1] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2]
    a[i][2] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2]
print(a[n][0] + a[n][1] + a[n][2])