h, m = map(int, input().split())

if(h == 0):
    print(h, end=' ')
else:
    print(12 - h, end=' ')

if(m == 0):
    print(m)
else:
    print(60 - m)
