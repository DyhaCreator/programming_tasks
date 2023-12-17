file = open('test', 'w')

n = 1000
file.write(str(n) + '\n')

for i in range(n):
    file.write(str(1000000) + '\n')