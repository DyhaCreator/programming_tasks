n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

ans = 0
for s in range(len(b)):
    start = -1
    lans = 0
    for i in range(s, len(b)):
        for j in range(start + 1, len(a)):
            #print(b[i], a[j])
            if(b[i] == a[j]):
                start = j
                lans += 1
                break
    ans = max(ans, lans)
print(ans)