def f(n):
    while (n > 0):
        if (n % 10 == 4): return True
        n = n // 10
    return False

ans = 0
n = int(input())
for i in range(n + 1):
    if (f(i)):
        ans += 1
        #print(i)

print(ans)