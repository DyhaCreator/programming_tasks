n = int(input())
a = list(map(int, input().split()))
n = int(input())

def F(n):
    if(n == 0):
        return []
    if(n < 0):
        return [float('inf')]
    ret = [float('inf')]
    ans = 0
    for i in range(len(a)):
        r = F(n - a[i])
        if(len(r) < len(ret) and r[0] > 0 and r[0] != float('inf')):
            ret = r.copy()
            ans = a[i]
    ret.append(ans)
    return ret

print(F(n))