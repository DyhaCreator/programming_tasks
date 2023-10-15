n = int(input())

def kus(m):
    if(m == n or n - m == 1):
        return 1
    return kus(m + 1) + kus(m + 2)

print(kus(0))
