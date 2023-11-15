import random

f = open('testc', 'w')

n, m = 5000, 5000

f.write(str(n) + ' ' + str(m) + '\n')

for i in range(n):
    s = ''
    for j in range(m):
        s += str(random.randint(0, 1)) + ' '
    s += '\n'
    f.write(s)