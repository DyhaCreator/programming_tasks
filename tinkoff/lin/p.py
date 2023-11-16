n = int(input())
k = int(input())

def f(n):
    ans = 1
    for i in range(1, n):
        ans *= i
    return ans

print((f(n)//(f(n - k)*f(k))))