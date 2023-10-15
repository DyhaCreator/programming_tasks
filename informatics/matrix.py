n = int(input())

for y in range(0, n):
    for x in range(0, n):
        if(x < n - 1 - y):
            print(0,end='')
        elif(x == n - 1 - y):
            print(1,end='')
        else:
            print(2,end='')
    print()