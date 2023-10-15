n = int(input())
ans = 0

def zoo(k):
    if(len(k) == n):
        #print(k)
        global ans
        ans += 1
    else:
        k.append(0)
        zoo(k.copy())
        if(k[len(k) - 2] == 0):
            k[len(k) - 1] = 1
            zoo(k.copy())

k = []
zoo(k.copy())
print(ans)