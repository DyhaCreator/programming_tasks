n, m = map(int, input().split())

matrix = []

for i in range(n):
    ma = '.' + input() + '.'
    matrix.append(ma)
ma = '.' * (m + 2)
matrix.append(ma)

l = []

def size(x, y):
    #print(x, y, matrix[y][x])
    if (matrix[y][x] == '|'):
        l.append((x, y))
        if(matrix[y + 1][x] == '|'):
            return size(x, y + 1) + 1
        else:
            return 1
    if (matrix[y][x] == '-'):
        l.append((x, y))
        if(matrix[y][x + 1] == '-'):
            return size(x + 1, y) + 1
        else:
            return 1
    if (matrix[y][x] == '/'):
        l.append((x, y))
        if(matrix[y + 1][x - 1] == '/'):
            return size(x - 1, y + 1) + 1
        else:
            return 1
    if (matrix[y][x] == '\\'):
        l.append((x, y))
        if(matrix[y + 1][x + 1] == '\\'):
            return size(x + 1, y + 1) + 1
        else:
            return 1
    return 0

ans = 0

for y in range(n):
    for x in range(1, m+1):
        b = False
        for i in range(len(l)):
            if((x, y) == l[i]):
                b = True
                break
        if(b == False):
            #print('-----')
            if(size(x, y) > 0):ans+=1

            

print(ans)

'''

4 5
..|/.
--|..
./|./
/.|/.

10 10
........./
......../.
......./..
....../...
...../....
..../.....
----------
....|.....
....|.....
....|.....

'''