n = int(input())

def hp(n):
    if(n == 0 or n == 1):
        return 1
    if(n % 2 == 0):
        return hp(n // 2) + 1
    else:
        return hp(n + 1) + hp((n - 1) // 2)
#for i in range(n):print(hp(i), end=' ')
print(hp(n))
