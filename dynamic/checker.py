x, y = map(int, input().split())

a = [0] * 8
for i in range(8):
    a[i] = [0] * 8
for i in range(8):
    for j in range(8):
        if(i == y - 1 and j == x - 1):
            a[i][j] = 1
        if(i > 0 and j > 0):
            a[i][j] += a[i - 1][j - 1]
        if(i > 0 and j < 7):
            a[i][j] += a[i - 1][j + 1]
print(sum(a[7]))