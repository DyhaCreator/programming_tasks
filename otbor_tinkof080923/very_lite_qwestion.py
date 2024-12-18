N, x, y = map(int, input().split())
l = min(x, y)
r = N * x * y
while(l < r):
    m = (l + r) // 2
    if((1 + (m - min(x, y)) // x + (m - min(x, y)) // y) < N):
        l = m + 1
    else:
        r = m
print(r)