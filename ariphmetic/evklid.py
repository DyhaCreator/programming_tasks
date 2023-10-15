def gcd(a, b):
    while(b > 0):
        a %= b
        c = a
        a = b
        b = c
    return a

a = int(input())
b = int(input())

print(gcd(a, b))