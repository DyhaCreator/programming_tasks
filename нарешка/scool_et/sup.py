a = int(input())
b = int(input())

def f(a):
    ans = 0
    for i in range(0, a + 1):
        s = 0
        b = i
        while(b > 0):
            s += b % 10
            b = b // 10
        if(s % 2 == 1):
            ans += 1
    return ans

print(f(b) - f(a - 1))