n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

c = [0] * (len(b) + 1)
for i in range(len(b) + 1):
    c[i] = [[]] * (len(a) + 1)

for j in range(1, len(a) + 1):
    for i in range(1, len(b) + 1):
        if(a[j - 1] == b[i - 1]):
            c[i][j] = c[i - 1][j - 1].copy()
            c[i][j].append(a[j - 1])
        else:
            if(len(c[i - 1][j]) > len(c[i][j - 1])):
                c[i][j] = c[i - 1][j].copy()
            else:
                c[i][j] = c[i][j - 1].copy()
for i in range(len(c[len(b)][len(a)])):
    print(c[len(b)][len(a)][i], end=' ')
print()