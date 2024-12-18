N, K = map(int, input().split())
st = list(map(int, input().split()))
l = 0
r = st[len(st) - 1] - st[0]

while(l < r - 1):
    m = (l + r) // 2
    cows = 1
    i = 0
    while(i < len(st) - 1):
        for j in range(i + 1, len(st)):
            #print(st[i], st[j])
            if(st[j] - st[i] >= m):
                i = j - 1
                cows += 1
                break
        i += 1
    print(cows, l, r, m)
    if(cows < K):
        r = m
    else:
        l = m
print(r)

'''
6 3
2 5 7 11 15 20

6 3
2 5 7 12 15 22
'''