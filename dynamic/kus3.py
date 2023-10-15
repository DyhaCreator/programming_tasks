n, k = map(int, input().split())

def kus(m):
    if(m >= n):
        return 1
    else:
        #print(m)
        ans = 0
        for i in range(1, min(n - m + 1, k + 1)):
            ans += kus(m + i)
        return ans

print(kus(0))
