w = list(map(int, input().split()))
v = list(map(int, input().split()))
A = int(input())

a = [0] * (A + 1)
for i in range(A + 1): 
    a[i] = [0] * (len(w) + 1)

for j in range(1, len(a)):
    for i in range(1, len(a[0])):
        if(j - w[i - 1] >= 0):
            a[j][i] = max(a[j][i - 1], a[j - w[i - 1]][i - 1] + v[i - 1])
        else:
            a[j][i] = a[j][i - 1]
print(a[A][len(w)])