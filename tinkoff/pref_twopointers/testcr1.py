file = open('test', 'w')

n = 100000
file.write(str(n) + '\n')
string = ''
for i in range(n):
    string += str(i) + ' '

file.write(string)