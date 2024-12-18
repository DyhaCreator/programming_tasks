n = int(input())
r = int(input())
c = int(input())

print(min(r - 1, c - 1) + min(n - r, c - 1) + min(r - 1, n - c) + min(n - r, n - c))