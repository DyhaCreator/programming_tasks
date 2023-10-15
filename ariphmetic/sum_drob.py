import math

a, b, c, d = map(int, input().split())

n = math.lcm(b, d)

a *= n // b
c *= n // d
a += c

k = math.gcd(a, n)
print(a // k, n // k)