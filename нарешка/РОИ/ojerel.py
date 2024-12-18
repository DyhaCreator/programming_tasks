n = int(input())

a = list(map(int, input().split()))

def sorted(a):
    for i in range(len(a)):
        c = True
        for j in range(len(a) - 1):
            b = i + j
            b2 = i + j + 1
            if(b > len(a) - 1):
                b -= len(a)
            if(b2 > len(a) - 1):
                b2 -= len(a)
            if(a[b] > a[b2]):
                c = False
            #print(a[b], end=' ')
        #print(c)
        if(c == True):
            return True
    return False

print(sorted(a))