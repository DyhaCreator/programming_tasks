n = 2025
ans = 0
while (n != 1):
    if (n % 2 == 0):
        n /= 2
    else:
        n = n * 3 + 1
    ans += 1
print(ans)
