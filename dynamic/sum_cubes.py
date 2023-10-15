n = int(input())

a = [0] * (n + 1)
for i in range(n + 1):
    a[i] = [0] * (int(n ** (1. / 3.)) + 1)

def F(n):
    print(n)
    if(n == 0):
        return 0
    if(n < 0):
        return float('inf')
    ret = float('inf')
    for i in range(1, int(n ** (1. / 3.)) + 1):
        a = F(n - i ** 3)
        if(ret > a):
            ret = a
    return ret + 1


print(F(n))